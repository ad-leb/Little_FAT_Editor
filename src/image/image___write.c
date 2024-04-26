#include "../defs.h"

extern int						data___image_fd;


int lseek (int, int, int);
int write (int, void*, int);

void helpr___error (int);


void image___write (void* this, int off, int len)
{
	if ( lseek(data___image_fd, off, 0) == -1 )									helpr___error(ERR_SEEK);
	if ( write(data___image_fd, this, len) != len )								helpr___error(ERR_WRTE);
}
