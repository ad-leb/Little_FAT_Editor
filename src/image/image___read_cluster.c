#include "header.h"


extern int						data___cluster_size;
extern int						data___data_off;

void image___read (void*, int, int);



void image___read_cluster (void* to, int cluster)
{
	int							offset;


	offset = data___cluster_size * (cluster - 2) + data___data_off;
	image___read(to, offset, data___cluster_size);
}
