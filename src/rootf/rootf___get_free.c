#include "header.h"


extern void*					data___root_table;





struct root_entry* rootf___get_free ()
{
	struct root_entry*				slot;


	slot = data___root_table;
	while (1) {
		if ( slot->name[0] == 0 || slot->name[0] == 0xE4 )						return slot;
		slot += ROOT_SIZE;
	}
}
