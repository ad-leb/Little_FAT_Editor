#include <defs.h>

int printf (const char*, ...);
int open (unsigned char*, int);
int close (int);

void helpr___error (int);

void inter___write_file (unsigned char*, int);



int push (unsigned char* file_name[])
{
	int							edited = 0;
	int							file_d;



	for (int i = 0; file_name[i] != NULL; i++) {
		file_d = open(file_name[i], 0);
			if ( file_d == -1 )													helpr___error(ERR_OPEN);
		inter___write_file(file_name[i], file_d);
			if ( close(file_d) == -1 )											helpr___error(ERR_CLOS);
		edited++;
	}


	return edited;
}
