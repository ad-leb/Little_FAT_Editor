#include <dirent.h>
#include <defs.h>


int chdir (char*);

void helpr___error (int);
int helpr___strcmp (unsigned char*, unsigned char*, int);

void push_file (unsigned char*);
void push_dir (unsigned char*);



void push_dir (unsigned char* dir_name)
{
	DIR*						dir;
	struct dirent*				ent = (void*) 1;



	dir = opendir(dir_name);
		if ( dir == NULL )														helpr___error(ERR_OPEN);


	if ( chdir(dir_name) == -1 )												helpr___error(ERR_CDIR);

	while ( ent ) {
		ent = readdir(dir);
			if ( ent == NULL )								break;
			if ( helpr___strcmp(".", ent->d_name, 1) == 0 )	continue;
		switch ( ent->d_type ) {
			case DT_REG	:			push_file(ent->d_name);			break;
			case DT_DIR	:			push_dir(ent->d_name);			break;
			default		:											break;
		}
	}

	if ( chdir("..") == -1 )													helpr___error(ERR_CDIR);
	if ( closedir(dir) == -1 )													helpr___error(ERR_CLOS);
}
