#include "header.h"


extern int						data___fat_off;
extern int						data___fat2_off;
extern int						data___root_off;
extern int						data___fat_size;
extern int						data___root_size;

extern void*					data___fat_table;
extern void*					data___root_table;


void image___write (void*, int, int);


void image___recover ()
{
	image___write(data___fat_table, data___fat_off, data___fat_size);
	image___write(data___fat_table, data___fat2_off, data___fat_size);
	image___write(data___root_table, data___root_off, data___root_size);
}
