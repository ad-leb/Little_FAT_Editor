#include "../../type.c"


struct root_entry {
	BYTE						name[8];
	BYTE 						exp[3];
	BYTE						attr;
	BYTE						unused;
	BYTE						create_time_ms;
	WORD						create_time;
	WORD						create_date;
	WORD						last_access;
	WORD						EA_index;
	WORD						modify_time;
	WORD						modify_date;
	WORD						off;
	DWORD						size;
};
