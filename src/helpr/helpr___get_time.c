#include "header.h"
#include <time.h>


extern word							data___date;
extern word							data___time;



void helpr___get_time ()
{
	time_t 						raw_time;
	struct tm*					format_time;


	raw_time = time(NULL);
	format_time = localtime(&raw_time);


	data___date = 0;
	data___date |= format_time->tm_year - 80;
	data___date <<= 4;
	data___date |= format_time->tm_mon + 1;
	data___date <<=5;
	data___date |= format_time->tm_mday;

	data___time = 0;
	data___time |= format_time->tm_hour;
	data___time <<= 6;
	data___time |= format_time->tm_min;
	data___time <<= 5;
	data___time |= format_time->tm_sec;
}
