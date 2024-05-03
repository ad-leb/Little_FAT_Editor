#include <sys/stat.h>
#include <defs.h>

void helpr___error (int);


int check_file_type (unsigned char* file_name)
{
	struct stat					info;


	if ( lstat(file_name, &info) == -1 )									helpr___error(ERR_OPEN);
	if ( (info.st_mode & S_IFMT) == S_IFDIR )								return 1;
	if ( (info.st_mode & S_IFMT) != S_IFREG ) 								return 2;
																			return 0;
}
