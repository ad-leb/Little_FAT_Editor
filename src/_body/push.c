#include <defs.h>

int printf (const char*, ...);
int open (unsigned char*, int);
int close (int);

void helpr___memreset (void*, int);
void helpr___get_fat_name (unsigned char*, unsigned char*);
void helpr___error (int);

void inter___write_file (unsigned char*, int);



int push (unsigned char* file_name[])
{
	unsigned char				fat_name[11];
	int							edited = 0;
	int							file_d;



	for (int i = 0; file_name[i] != NULL; i++) {
		file_d = open(file_name[i], 0);
			if ( file_d == -1 )													helpr___error(ERR_OPEN);

		helpr___memreset(fat_name, 11);
		helpr___get_fat_name(fat_name, file_name[i]);

		inter___write_file(fat_name, file_d);
			if ( close(file_d) == -1 )											helpr___error(ERR_CLOS);

		edited++;
	}


	return edited;
}
