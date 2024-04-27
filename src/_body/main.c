#include <fcntl.h>
#include "defs.h"

extern int						data___image_fd;
extern int						conf___file_first;
extern int						conf___file_count;
extern int						conf___image_name;
extern void*					conf___choosen_action;



void configure ();
void image___configure ();
void image___record ();
void helpr___exit (int);
void helpr___error (int);




int main (int argc, char* argv[])
{
	int							file_d;


	configure(argc, argv);

	data___image_fd = open(conf___image_name, O_RDONLY);
		if ( data___image_fd == -1 )											helpr___error(ERR_OPEN);
	image___configure();


	for (int i = conf___file_first; i < argc; i++) {
		if ( (file_d = open(argv[i], O_RDWR)) == -1 )							helpr___error(ERR_OPEN);
		conf___choosen_action();
		close(file_d);
	}
	if ( conf___changing ) 				image___record();
	
	
																				helpr___exit(0);
}
