#include "header.h"


extern word							data___date;
extern word							data___time;


void rootf___resize_entry (struct root_entry* entry, dword new_size)
{
	entry->size = new_size;
	entry->modify_time = data___time;
	entry->modify_date = data___date;
	entry->last_access = data___date;
}
