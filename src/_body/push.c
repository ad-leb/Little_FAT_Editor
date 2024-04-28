#include <defs.h>

int printf (const char*, ...);



void push (unsigned char* files[])
{
	int							file_d;


	for (int i = 0; files[i] != NULL; i++)
		printf("%s\n", files[i]);
}
