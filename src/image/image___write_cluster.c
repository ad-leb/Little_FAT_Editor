#include "header.h"


extern int						data___cluster_size;
extern int						data___data_off;

void image___write (void*, int, int);



void image___write_cluster (void* from, int cluster)
{
	int							offset;


	offset = data___cluster_size * (cluster - 2) + data___data_off;
	image___write(from, offset, data___cluster_size);
}
