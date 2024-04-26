#include "defs.h"


void helpr___exit (int);


void error (int code)
{
	switch ( code ) {
		case ERR_OPEN	:				helpr___exit(ERR_OPEN);				break;
		case ERR_LALL	:				helpr___exit(ERR_LALL);				break;
		case ERR_READ	:				helpr___exit(ERR_READ);				break;
		case ERR_WRTE	:				helpr___exit(ERR_WRTE);				break;
		case ERR_SEEK	:				helpr___exit(ERR_SEEK);				break;
		default			:				helpr___exit(99);					break;
	}
}
