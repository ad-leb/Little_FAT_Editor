#include "type.c"


struct root_entry*  rootf___found_by_name (unsigned char*);


int rootf___get_first_cluster (unsigned char* name)
{
	struct root_entry*			entry;


	entry = rootf___found_by_name (name);
	if ( entry == NULL )														return 0;
	else																		return entry->off;
}
