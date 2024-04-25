#include "type.c"


struct root_entry* rootf___get_free ();
void helpr___strcpy (unsigned char*, unsigned char*, int);




void rootf___new_entry (byte* name, byte* exp, word off, dword size)
{
	struct root_entry* 			entry;


	entry = rootf___get_free();

	helpr___strcpy(entry->name, name, 8);
	helpr___strcpy(entry->exp, exp, 3);
	/* time, date and either */
	entry->off = off;
	entry->size = size;
}
