
int printf (const char*, ...);



void push (unsigned char* files[])
{
	int							file_d;


	for (int i = 0; files[i] != 0; i++) {
		printf("%s\n", files[i]);
	}
}
