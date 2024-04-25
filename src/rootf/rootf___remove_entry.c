#include "type.c"


void rootf___remove_entry (struct root_entry* entry)
{
	entry->name[0] = 0xE5;
}
