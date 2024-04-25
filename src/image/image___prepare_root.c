#include "type.c"
#include "../defs.h"


extern struct image_info		data___image_info;

extern int						data___fat_off;
extern int						data___fat_size;

extern int						data___root_size;
extern int						data___root_off;
extern int						data___root_entries_count;
extern void*					data___root_table;

void* malloc (int);
void  error (int);

void  image___read (void*, int, int);



void image___prepare_root ()
{
	data___root_off = data___fat_off + data___fat_size * 2;
	data___root_entries_count = data___image_info.bpb.re;
	data___root_size = data___root_entries_count * ROOT_SIZE;
	data___root_table = malloc(data___root_size);
	if ( data___root_table == NULL )											error(ERR_MALL);
	image___read(data___root_table, data___root_off, data___root_size);
}
