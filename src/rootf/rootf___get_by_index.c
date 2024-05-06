#include "header.h"

struct root_entry* rootf___get_first_entry ();
struct root_entry* rootf___get_next_entry (struct root_entry*);


struct root_entry* rootf___get_by_index (int index)
{
	int							curr = 0;
	struct root_entry*			entry;


	entry = rootf___get_first_entry();
	while ( curr < index ) {
		entry = rootf___get_next_entry (entry);
		curr++;
	}																			return entry;
}
