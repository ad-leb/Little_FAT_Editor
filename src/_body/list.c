#include <defs.h>


void inter___print_title ();
void inter___print_content ();

int helpr___strcmp (unsigned char*, unsigned char*, int);
void helpr___error (int);


int list (unsigned char* request[])
{
	if ( helpr___strcmp(request[0], "title", 5) == 0 )
		inter___print_title();
	else if ( helpr___strcmp(request[0], "content", 7) == 0 )
		inter___print_content();
	else
		helpr___error(ERR_UNKN);


	return 0;
}
