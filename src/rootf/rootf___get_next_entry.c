#include "header.h"


extern void*					data___root_table;
extern int						data___root_size;



void* rootf___get_next_entry (byte* entry)
{
	do {
		entry += ROOT_SIZE;
	} while ( *entry == 0xE5 );

	if ( *entry == 0 )															return NULL;
	else																		return entry;
}
