#include "header.h"


extern int						data___cluster_size;
extern int						data___data_off;

int image___read (void*, int, int);



int image___read_cluster (void* to, int cluster, int len)
{
	int							offset;


	offset = data___cluster_size * (cluster - 2) + data___data_off;

	if ( len == 0 )																return image___read(to, offset, data___cluster_size);
	else 																		return image___read(to, offset, len);
}
