#include "type.c"
#include "../defs.h"


extern struct image_info		data___image_info;

extern int						data___fat_off;
extern int						data___fat2_off;
extern int						data___fat_size;
extern void*					data___fat_table;

void* malloc (int);
void  error (int);

void  image___read (void*, int, int);



void image___prepare_fat ()
{
	data___fat_off = data___image_info.bpb.rs * SECTOR_SIZE;
	data___fat_size = data___image_info.bpb.spf * SECTOR_SIZE;
	data___fat2_off = data___fat_off + data___fat_size;
	data___fat_table = malloc(data___fat_size);
	if ( data___fat_table == NULL )												error(ERR_MALL);
	image___read(data___fat_table, data___fat_off, data___fat_size);
}
