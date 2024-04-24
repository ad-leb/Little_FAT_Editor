#include "root_entry.c"

#define ROOT_SIZE				20


extern int* 					data___root_table;


void image___read (void*, void*, int);
int helpr___namecmp (unsigned char*, unsigned char*);


int rootf___found_by_name (struct root_entry* entry, unsigned char* name)
{
	int*						ptr;


	ptr = data___root_table;
	while (1) {
		image___read(entry, ptr, ROOT_SIZE);

		if ( *(entry->name) == 0 )												return 1;
		if ( helpr___namecmp(entry->name, name) == 0 )							return 0;
	}
}
