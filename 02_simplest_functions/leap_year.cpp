#include <stdio.h>
#include <time.h>


bool isLeapYear ( int _year )
{
	if ( _year % 4 != 0 )
		return false;

	else if ( _year % 100 == 0 )
		return ( _year % 400 == 0 );

	else
		return true;
}


int getDaysInYear ( int _year )
{
	return isLeapYear( _year ) ? 366 : 365;
}


int getYear ( time_t _currentTime )
{
	const int SECONDS_IN_DAY = 24 * 3600;

	int currentYear = 1970;
	
	while ( true )
	{
		int secondsInCurrentYear = getDaysInYear( currentYear ) * SECONDS_IN_DAY;
		if ( _currentTime < secondsInCurrentYear )
			return currentYear;

		else
		{
			++ currentYear;
			_currentTime -= secondsInCurrentYear;
		}
	}

	return 0;
}


int main ()
{
	time_t currentTime;
	time( & currentTime );

	int year = getYear( currentTime );
	printf( "%d %s leap\n", year, isLeapYear( year ) ? "is" : "is not" );
}
