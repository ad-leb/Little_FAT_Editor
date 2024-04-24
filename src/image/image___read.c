void err_exit (int);
int read (void*, void*, int);


void image___read (void* to, void* from, int len)
{
	if ( read(from, to, len) != len )											err_exit(1);
}
