#include "header.h"


void helpr___exit (int);


/* Yeah, it must be done in the end. I dunno, how it gonna work yet */


void helpr___error (int code)
{
	switch ( code ) {
		case ERR_OPEN	:				helpr___exit(ERR_OPEN);				break;
		case ERR_LALL	:				helpr___exit(ERR_LALL);				break;
		case ERR_READ	:				helpr___exit(ERR_READ);				break;
		case ERR_WRTE	:				helpr___exit(ERR_WRTE);				break;
		case ERR_SEEK	:				helpr___exit(ERR_SEEK);				break;
		case ERR_NFND	:				helpr___exit(ERR_NFND);				break;
		case ERR_CLOS	:				helpr___exit(ERR_CLOS);				break;
		case ERR_UNKN	:				helpr___exit(ERR_UNKN);				break;
		default			:				helpr___exit(99);					break;
	}
}
