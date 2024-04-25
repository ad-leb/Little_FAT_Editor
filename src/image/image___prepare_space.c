#include "type.c"


extern int						data___root_size;
extern void*					data___root_table;

extern void*					data___space;



void image___prepare_space ()
{
	data___space = data___root_table + data___root_size;
}
