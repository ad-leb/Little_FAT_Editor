#include "header.h"


extern void*					data___root_table;
extern int						data___root_size;

void helpr___error (int);





struct root_entry* rootf___get_free ()
{
	struct root_entry*				slot;


	slot = data___root_table;
	while (1) {
		if ( (void*) slot >= (void*) (data___root_table + data___root_size) )	helpr___error(ERR_LIMT);
		if ( slot->name[0] == 0 || slot->name[0] == 0xE5 )						return slot;
		slot += 1;
	}
}
