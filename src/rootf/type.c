#include "../type.c"

struct root_entry {
	byte						name[8];
	byte 						exp[3];
	byte						attr;
	byte						unused;
	byte						create_time_ms;
	word						create_time;
	word						create_date;
	word						last_access;
	word						EA_index;
	word						modify_time;
	word						modify_date;
	word						off;
	dword						size;
};
