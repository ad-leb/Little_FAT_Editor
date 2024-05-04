#include "header.h"


extern int						data___params;

extern struct image_info		data___image_info;

extern int						data___fat_off;
extern int						data___fat2_off;
extern int						data___fat_size;

extern void*					data___fat_table;



void  fat12___set (int, int);

void  image___read (void*, int, int);

void  helpr___error (int);
void  helpr___memreset (void*, int);
void* helpr___lalloc (int);



void image___prepare_fat ()
{
	data___fat_off = data___image_info.bpb.rs * SECTOR_SIZE;
	data___fat_size = data___image_info.bpb.spf * SECTOR_SIZE;
	data___fat2_off = data___fat_off + data___fat_size;

	data___fat_table = helpr___lalloc(data___fat_size);
		if ( data___fat_table == (void*) -1 )									helpr___error(ERR_LALL);

	if ( PARAM_CLEAR ) {
		helpr___memreset(data___fat_table, data___fat_size);
		fat12___set(0, 0xff0);
		fat12___set(1, 0xfff);
	} else {
		image___read(data___fat_table, data___fat_off, data___fat_size);
	}
}
