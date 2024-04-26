#include "type.c"
#include "../defs.h"


extern struct image_info		data___image_info;
extern int						data___data_off;


void image___read (void*, int, int);



void image___read_sector (void* to, int cluster)
{
	int							sector;
	int							off;


	sector = (cluster - 2 ) * data___image_info.bpb.spc;
	off = (sector * SECTOR_SIZE) + data___data_off;
	image___read(to, off, 512);
}
