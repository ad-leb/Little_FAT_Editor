#include <fcntl.h>
#include "defs.h"

extern int						data___image_fd;



void image___configure ();
void helpr___exit (int);

void error (int);




int main (int argc, char* argv[])
{
	data___image_fd = open("floppy.img", O_RDONLY);
		if ( data___image_fd == -1 )											error(ERR_OPEN);

	image___configure();														helpr___exit(0);
}
