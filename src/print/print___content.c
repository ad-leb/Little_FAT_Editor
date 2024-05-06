#include <defs.h>


void* rootf___get_first_entry ();
void* rootf___get_next_entry (void*);

void helpr___get_outter_name (unsigned char*, unsigned char*);
void helpr___memreset (void*, int);
void helpr___itod (unsigned char*, int);
void helpr___error (int);
int helpr___strcat (unsigned char*, unsigned char*, int);

int write (int, unsigned char*, int);


void print___content ()
{
	int							curr = 0;
	void*						entry;
	unsigned char				line[512];
	unsigned char				outter_name[11];
	int							len;


	entry = rootf___get_first_entry();
	while ( entry != NULL ) {
		helpr___get_outter_name(outter_name, entry);
		helpr___memreset(line, 512);

		helpr___itod(line, curr);
		len = helpr___strcat(line, "\r\t", 2);
		len = helpr___strcat(line, outter_name, 11);
		len = helpr___strcat(line, "\n", 1);
		if ( write(1, line, len) != len )										helpr___error(ERR_WRTE);

		entry = rootf___get_next_entry(entry);
		curr++;
	}
}
