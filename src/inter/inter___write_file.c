#include <defs.h>
#include <type.c>


extern unsigned char*			data___buffer;
extern int						data___cluster_size;


void* rootf___get_by_name (unsigned char*);
void* rootf___new_entry (unsigned char*, int, int);
int rootf___get_first_cluster (void*);
void rootf___resize_entry (void*, dword);

int fat12___get_free ();
int	fat12___get_next ();
void fat12___set (int, int);

void helpr___error (int);
void helpr___memreset (void*, int);
void* helpr___lalloc (int);

void image___write_cluster (void*, int);

int read (int, void*, int);



void inter___write_file (unsigned char* file_name, int file_d)
{
	void*						root_entry;
	int							cluster;
	int							old_cluster;

	int							len;
	int							summ = 0;



	root_entry = rootf___get_by_name (file_name);
	if ( root_entry == NULL ) {
		cluster = fat12___get_free();
		root_entry = rootf___new_entry(file_name, cluster, 0);
	} else {
		cluster = rootf___get_first_cluster(root_entry);
	}
	old_cluster = cluster;


	helpr___memreset(data___buffer, data___cluster_size);
	len = read(file_d, data___buffer, data___cluster_size);
	summ += len;
	while ( len > 0 ) {
		old_cluster = cluster;
		image___write_cluster(data___buffer, cluster);

		fat12___set(cluster, 0xff8);
		cluster = fat12___get_free();
		fat12___set(old_cluster, cluster);

		
		helpr___memreset(data___buffer, data___cluster_size);
		len = read(file_d, data___buffer, data___cluster_size);
		summ += len;
	}
	

	if ( len == -1 )															helpr___error(ERR_READ);

	fat12___set(old_cluster, 0xfff);
	rootf___resize_entry(root_entry, summ);										return;
}
