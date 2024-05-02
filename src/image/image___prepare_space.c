#include "header.h"


extern int						data___root_size;
extern int						data___root_off;

extern int						data___data_off;



void image___prepare_space ()
{
	data___data_off = data___root_off + data___root_size;
}
