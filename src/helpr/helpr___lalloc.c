#include <defs.h>

/* lol allocate */

void helpr___error (int);
void* sbrk (int);


void* helpr___lalloc (int size)
{
	void*						chk;


	chk = sbrk(size);
	if ( chk == (void*) -1 )													helpr___error(ERR_LALL);
	else																		return sbrk(size);
}
