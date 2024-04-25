#include <type.c>

short							data___image_fd;


struct image_info				data___image_info;



int								data___fat_off;
int								data___root_off;
int								data___data_off;

void*							data___fat_table;
void*							data___fat2_table;
void*							data___root_table;
void*							data___space;

int								data___fat_size;
int								data___root_size;
int								data___root_entries_count;
