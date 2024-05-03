#include <defs.h>


int check_file_type (unsigned char*);
void push_file (unsigned char*);
void push_dir (unsigned char*);
void helpr___error (int);



int push (unsigned char* file_name[])
{
	for (int i = 0; file_name[i] != NULL; i++) {
		switch ( check_file_type(file_name[i]) ) {
			case 0	:		push_file(file_name[i]);			break;
			case 1	:		push_dir(file_name[i]);				break;
			default	:		helpr___error(ERR_FTYP);			break;
		}
	}


	return 1;
}
