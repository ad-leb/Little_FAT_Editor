#include "header.h"


struct root_entry*  rootf___get_by_name (unsigned char*);


int rootf___get_first_cluster (struct root_entry* entry)
{
	if ( entry == NULL )														return 0;
	else																		return entry->off;
}
