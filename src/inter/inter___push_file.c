#include "../defs.h"



void inter___push_file (unsigned char* file_name, int file_d)
{
	void*						file_root_entry;
	int							file_cluster;

	unsigned char				buffer[SECTOR_SIZE];
	int							len;



	file_root_entry = rootf___found_by_name(file_name);
		if ( file_root_enty == NULL )  file_root_entry = rootf___get_free();
	file_cluster = fat12___get_free();


	len = read(file_d, buffer, sizeof(buffer));
	while ( len > 0 ) {
		image___write_
