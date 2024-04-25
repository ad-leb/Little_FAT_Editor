#include "type.c"


extern void* 					data___root_table;

int helpr___namecmp (unsigned char*, unsigned char*);



struct root_entry* rootf___found_by_name (unsigned char* name)
{
	struct root_entry*				entry;


	entry = data___root_table;
	while (1) {
		if ( entry->name[0] == 0 )												return NULL;
		if ( helpr___namecmp(entry->name, name) == 0 )							return entry;
		else 	entry += ROOT_SIZE;
	}
}
