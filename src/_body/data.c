#include <type.c>

unsigned char					data___program_name[256];
void*							data___program_name_end;
unsigned char					data___image_name[256];
void*							data___image_name_end;
long							data___image_fd;
long							data___image_flags = 0;
long							data___image_perms = 0666;
void*							data___procedure;

word							data___date;
word							data___time;

void*							data___buffer;


struct image_info				data___image_info;


/****************************************************************/
/*																*/
/*			Variables to operate with an image data				*/
/*																*/
/****************************************************************/
int								data___fat_off;
int								data___fat2_off;
int								data___root_off;
int								data___data_off;

int								data___fat_size;
int								data___root_size;
int								data___root_entries_count;
int								data___cluster_size;


/****************************************************************/
/*																*/
/*			Pointers to already loaded in memory tables			*/
/*																*/
/****************************************************************/
void*							data___fat_table;
void*							data___root_table;



int								data___params = 0;
