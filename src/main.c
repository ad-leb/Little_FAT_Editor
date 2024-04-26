#include <fcntl.h>
#include "defs.h"

extern int						data___image_fd;



void image___configure ();
void image___read_sector (void*, int);
int rootf___get_first_cluster (unsigned char*);
void helpr___exit (int);
void helpr___error (int);




int main (int argc, char* argv[])
{
	int							first_cluster;
	int							first_sector;
	unsigned char				buffer[512];


	data___image_fd = open("floppy.img", O_RDONLY);
		if ( data___image_fd == -1 )											helpr___error(ERR_OPEN);
	image___configure();


	first_cluster = rootf___get_first_cluster("STAGE_2");
		if ( first_cluster == 0 )												helpr___error(ERR_NFND);
	image___read_sector(buffer, first_cluster);


	first_cluster += 12;
	first_cluster *= 2;
	helpr___exit(first_cluster);
}
