/*	config space	*/
void conf_get_fs_type (int*);
void conf_get_fat_table (int**, int**);
void conf_get_root_table (int**);

/*	image space 	*/
int								fs_type;
int*							fat_table0;
int*							fat_table1;
int*							root_tabel;
void root_read ();



void prepare_image (int fd)
{
	image_fd = fd;

	conf_get_fs_type(*fs_type);
	conf_get_fat_table(*fat_table0, *fat_table1);
	conf_get_root_table(*root_table);

	root_read();
}
