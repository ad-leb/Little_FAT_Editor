#include "../defs.h"

extern int						data___image_fd;


int lseek (int, int, int);
int read (int, void*, int);

void error (int);


void image___read (void* to, int off, int len)
{
	if ( lseek(data___image_fd, off, 0) == -1 )									error(ERR_SEEK);
	if ( read(data___image_fd, to, len) != len )								error(ERR_READ);
}
