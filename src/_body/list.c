#include <defs.h>


void print___image_info ();
void print___content ();

int helpr___strcmp (unsigned char*, unsigned char*, int);
void helpr___error (int);


int list (unsigned char* request[])
{
	if ( helpr___strcmp(request[0], "title", 5) == 0 )
		print___image_info();
	else if ( helpr___strcmp(request[0], "content", 7) == 0 )
		print___content();
	else
		helpr___error(ERR_UNKN);


	return 0;
}
