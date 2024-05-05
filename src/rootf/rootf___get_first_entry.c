#include "header.h"


extern void*					data___root_table;
extern int						data___root_size;


void* rootf___get_next_entry (void*);



void* rootf___get_first_entry ()
{
	struct root_entry* 			entry;


	entry = data___root_table;

	if ( entry->name[0] != 0xE5 )												return entry;
	else if ( entry->name[0] == 0 )												return NULL;
	else																		return rootf___get_next_entry(data___root_table);
}
