#include "header.h"
#include <time.h>


extern word							data___date;
extern word							data___time;



void helpr___get_time ()
{
	time_t						raw;
	int							year;
	int							month;
	int							day;
	int							hour;
	int							min;
	int							sec;



	time(&raw);

	day = raw / 86400;
	raw %= 86400 * day;
	day++;

	year = 1970;
	while ( day > 366 ) {
		if ( (year % 4) == 0 ) {
			day -= 366;
			year++;
		} else {
			day -= 365;
			year++;
		}
	}

	month = 1;
	if ( day > 31 )				 	  { month++; day -= 31; }
	if ( day > 29 && year % 4 == 0 )  { month++; day -= 29; }	
	if ( day > 28 && year % 4 != 0 )  { month++; day -= 28; }
	if ( day > 31 )				 	  { month++; day -= 31; }
	if ( day > 30 )				 	  { month++; day -= 30; }
	if ( day > 31 )				 	  { month++; day -= 31; }
	if ( day > 30 )				 	  { month++; day -= 30; }
	if ( day > 31 )				 	  { month++; day -= 31; }
	if ( day > 31 )				 	  { month++; day -= 31; }
	if ( day > 30 )				 	  { month++; day -= 30; }
	if ( day > 31 )				 	  { month++; day -= 31; }
	if ( day > 30 )				 	  { month++; day -= 30; }

	hour = raw / 3600;
	raw %= 3600;

	min = raw / 60;
	raw %= 60;

	sec = raw;





	data___date = 0;
	data___date |= year - 80;
	data___date <<= 4;
	data___date |= month + 1;
	data___date <<=5;
	data___date |= day;

	data___time = 0;
	data___time |= hour;
	data___time <<= 6;
	data___time |= min;
	data___time <<= 5;
	data___time |= sec;
}
