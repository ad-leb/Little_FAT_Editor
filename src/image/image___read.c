#include "header.h"

extern int						data___image_fd;


int lseek (int, int, int);
int read (int, void*, int);

void helpr___error (int);


int image___read (void* to, int off, int len)
{
	int							readed;


	if ( lseek(data___image_fd, off, 0) == -1 )									helpr___error(ERR_SEEK);
	if ( (readed = read(data___image_fd, to, len)) != len )						helpr___error(ERR_READ);
	else																		return readed;
}
