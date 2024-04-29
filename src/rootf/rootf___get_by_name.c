#include "header.h"


extern void* 					data___root_table;

int helpr___strcmp (unsigned char*, unsigned char*, int);



struct root_entry* rootf___get_by_name (unsigned char* name)
{
	struct root_entry*				entry;


	entry = data___root_table;
	while (1) {
		if ( entry->name[0] == 0 )												return NULL;
		if ( helpr___strcmp(entry->name, name, 11) == 0 )						return entry;
		else 	entry += 1;
	}
}
