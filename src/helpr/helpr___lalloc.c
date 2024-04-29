#include <defs.h>

/* lol allocate */

void helpr___error (int);
void* sbrk (int);


void* helpr___lalloc (int size)
{
	int							chk;


	chk = sbrk(size);
	if ( chk == -1 )															helpr___error(ERR_LALL);
	else																		return sbrk(size);
}
