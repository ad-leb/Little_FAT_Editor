#include "header.h"


extern void*					data___root_table;
extern int						data___root_size;

void helpr___error (int);



void* rootf___get_next_entry (byte* entry)
{
	do {
		entry += ROOT_SIZE;
	} while ( *entry == 0xE5 );

	if ( *entry == 0 )															return NULL;
	if ( (void*) entry >= (void*) (data___root_table + data___root_size) )		helpr___error(ERR_LIMT);
	else																		return entry;
}
