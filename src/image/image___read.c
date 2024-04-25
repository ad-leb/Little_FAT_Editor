#include "../defs.h"
#include <unistd.h>

extern int						data___image_fd;

//int lseek (void*, int, int);
//int read (void*, void*, int);

void error (int);


void image___read (void* to, int off, int len)
{
	if ( lseek(data___image_fd, off, SEEK_SET) == -1 )							error(ERR_SEEK);
	if ( len = read(data___image_fd, to, len) != len )							error(ERR_READ);
}
