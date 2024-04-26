#include "type.c"


extern int						data___root_size;
extern void*					data___root_off;

extern void*					data___data_off;



void image___prepare_space ()
{
	data___data_off = data___root_off + data___root_size;
}
