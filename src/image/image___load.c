#include "header.h"


extern struct image_info		data___image_info;
extern int						data___cluster_size;
extern void*						data___buffer;

void image___read (void*, int, int);

void image___prepare_fat();
void image___prepare_root();
void image___prepare_space();

void* helpr___lalloc (int);



void image___load ()
{
	image___read(&data___image_info, 0, sizeof(data___image_info));

	data___cluster_size = SECTOR_SIZE * data___image_info.bpb.spc;
	data___buffer = helpr___lalloc(data___cluster_size);

	image___prepare_fat();
	image___prepare_root();
	image___prepare_space();
}
