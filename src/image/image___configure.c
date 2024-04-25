#include "../defs.h"
#include "type.c"


extern struct image_info		data___image_info;

void image___read (void*, int, int);

void image___prepare_fat();
void image___prepare_root();
void image___prepare_space();



void image___configure ()
{
	image___read(&data___image_info, 0, sizeof(data___image_info));

	image___prepare_fat();
	image___prepare_root();
	image___prepare_space();
}
