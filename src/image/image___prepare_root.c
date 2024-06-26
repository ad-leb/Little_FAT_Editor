#include "header.h"


extern int						data___params;

extern struct image_info		data___image_info;

extern int						data___fat_off;
extern int						data___fat_size;

extern int						data___root_size;
extern int						data___root_off;
extern int						data___root_entries_count;

extern void*					data___root_table;



void  image___read (void*, int, int);

void  helpr___error (int);
void  helpr___memreset (void*, int);
void* helpr___lalloc (int);



void image___prepare_root ()
{
	data___root_off = data___fat_off + data___fat_size * 2;
	data___root_entries_count = data___image_info.bpb.re;
	data___root_size = data___root_entries_count * ROOT_SIZE;

	data___root_table = helpr___lalloc(data___root_size);
		if ( data___root_table == (void*) -1 )									helpr___error(ERR_LALL);

	if ( PARAM_CLEAR ) {
		helpr___memreset(data___root_table, data___root_size);
	} else {
		image___read(data___root_table, data___root_off, data___root_size);
	}
}
