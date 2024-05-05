#include <type.c>
#include <defs.h>


extern unsigned char*			data___buffer;
extern int						data___cluster_size;


int rootf___get_size (void*);
int rootf___get_first_cluster (void*);
void rootf___resize_entry (void*, int);

int fat12___get_next(int);

int image___read_cluster (void*, int, int);

void helpr___get_outter_name (unsigned char*, unsigned char*);
void helpr___error (int);


int open (unsigned char*, int, int);
int write (int, unsigned char*, int);
int close (int);



void inter___read_file (void* entry) 
{
	unsigned char				file_name[12];
	int							file_d;

	int							cluster;
	int							size;



	helpr___get_outter_name(file_name, entry);
	file_d = open(file_name, 0x241, 0666);
		if ( file_d == -1 )														helpr___error(ERR_OPEN);


	size = rootf___get_size(entry);
	cluster = rootf___get_first_cluster(entry);
	while ( size > data___cluster_size && cluster < 0xff8 ) {
		size -= image___read_cluster(data___buffer, cluster, 0);
		cluster = fat12___get_next(cluster);
		if ( write(file_d, data___buffer, data___cluster_size) != data___cluster_size )
																				helpr___error(ERR_WRTE);
	}
	if ( cluster < 0xff8 )		  { image___read_cluster(data___buffer, cluster, size);
									if ( write(file_d, data___buffer, size) != size )
																				helpr___error(ERR_WRTE); }
	else							rootf___resize_entry(entry, rootf___get_size(entry) - size);


	if ( close(file_d) == -1 )													helpr___error(ERR_CLOS);
}
