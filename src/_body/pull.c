#include <defs.h>

extern unsigned char			data___image_name[256];
extern unsigned char*			data___image_name_end;


void* rootf___get_by_name (unsigned char*);
void* rootf___get_by_index (int);
void* rootf___get_first_entry ();
void* rootf___get_next_entry (void*);

int helpr___atoi (unsigned char*);
int helpr___strcmp (unsigned char*, unsigned char*, int);
int helpr___strcat (unsigned char*, unsigned char*, int);
void helpr___error (int);

void inter___read_file (void*);


int mkdir (unsigned char*, int);
int chdir (unsigned char*);



int pull (unsigned char* files[])
{
	void*						entry;
	unsigned char				dir_name[1024];



	dir_name[0] = 0;
	helpr___strcat(dir_name, "from_", 5);
	helpr___strcat(dir_name, data___image_name, data___image_name_end - data___image_name);

	mkdir(dir_name, 0777);
	if ( chdir(dir_name) == -1 )												helpr___error(ERR_CDIR);


	if ( helpr___strcmp("all\0", files[0], 3) == 0 ) {
		entry = rootf___get_first_entry();
		while ( entry != NULL ) {
			inter___read_file(entry);
			entry = rootf___get_next_entry(entry);
		}
	} else {
		for (int i = 0; files[i] != NULL; i++) {
			if ( *files[i] <= 0x39 && *files[i] >= 0x30 ) {
				if ( (entry = rootf___get_by_index(helpr___atoi(files[i]))) == NULL)
																				helpr___error(ERR_NFND);
			} else if ( (entry = rootf___get_by_name(files[i])) == NULL )	  { helpr___error(ERR_NFND); }

			inter___read_file(entry);
		}
	}


	if ( chdir("..") == -1 )													helpr___error(ERR_CDIR);
			


	return 0;
}
