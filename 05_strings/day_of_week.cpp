#include <stdio.h>

const char* dayOfWeek ( int _day )
{
	static const char* s_DayNames [] = 
		{
		    "Illegal day",
		    "Monday",
		    "Tuesday",
		    "Wednesday",
		    "Thursday",
		    "Friday",
		    "Saturday",
		    "Sunday"
		};
		
	return ( _day >= 1 && _day <= 7 ) ? s_DayNames[ _day ] : s_DayNames[ 0 ];
}


int main ()
{
	int day;
	scanf( "%d", & day );
	printf( "%s\n", dayOfWeek( day ) );
	return 0;
}          
