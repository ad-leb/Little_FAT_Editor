#include "header.h"



extern word							data___date;
extern word							data___time;


struct root_entry* rootf___get_free ();

void helpr___strncpy (unsigned char*, unsigned char*, int);




void* rootf___new_entry (byte* name, word off, dword size)
{
	struct root_entry* 			entry;


	entry = rootf___get_free();

	helpr___strncpy(entry->name, name, 11);
	entry->attr = 0x20;
	entry->create_time = data___time;
	entry->create_date = data___date;
	entry->off = off;
	entry->size = size;

	return entry;
}
