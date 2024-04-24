#include "root_entry.c"


int rootf___found_by_name (struct root_entry*, unsigned char*);


int rootf___get_first_sect (unsigned char* name)
{
	struct root_entry			entry;


	if ( rootf___found_by_name(&entry, name) != 0 )								return 0;
	else																		return entry.off;
}
