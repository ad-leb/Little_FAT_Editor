#include <defs.h>

void helpr___error (int);
void* sbrk (int);


/* I didn't want to use the 'stdlib.h', so I get an 'sbrk' syscall and pack it to the 'lol allocate' in case if I will realy need a normal 'mem allocate'. Lol */


void* helpr___lalloc (int size)
{
	void*						chk;


	chk = sbrk(size);
	if ( chk == (void*) -1 )													helpr___error(ERR_LALL);
	else																		return sbrk(size);
}
