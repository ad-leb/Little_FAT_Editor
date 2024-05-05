#include <defs.h>


void* rootf___get_by_name(unsigned char*);
void* rootf___get_first_entry ();
void* rootf___get_next_entry (void*);

void helpr___error (int);
int helpr___strcmp (unsigned char*, unsigned char*, int);

void inter___read_file (void*);


int mkdir (unsigned char*, int);
int chdir (unsigned char*);



int pull (unsigned char* files[])
{
	void*						entry;



	mkdir("pulled_files", 0777);
	if ( chdir("pulled_files") == -1 )											helpr___error(ERR_CDIR);


	if ( helpr___strcmp("all\0", files[0], 3) == 0 ) {
		entry = rootf___get_first_entry();
		while ( entry != NULL ) {
			inter___read_file(entry);
			entry = rootf___get_next_entry(entry);
		}
	} else {
		for (int i = 0; files[i] != NULL; i++) {
			if ( (entry = rootf___get_by_name(files[i])) == NULL )				helpr___error(ERR_NFND);
			inter___read_file(entry);
		}
	}


	if ( chdir("..") == -1 )													helpr___error(ERR_CDIR);
			


	return 0;
}
