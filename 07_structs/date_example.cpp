#include <stdio.h>


static const int DAYS_IN_MONTHS[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
static const char * MONTH_NAMES [] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };


struct Date
{
	int year;
	int month;
	int day;
};


bool isLeapYear ( int _year )
{
    if ( _year % 4 != 0 )
        return false;

    else if ( _year % 100 == 0 )
        return ( _year % 400 == 0 );

    else
        return true;
}


Date readDate ()
{
	Date d;
	scanf( "%d %d %d", & ( d.year ), &( d.month ), &( d.day ) );
	return d;
}


void printDate ( Date d )
{
	printf( "%s %d, %d", MONTH_NAMES[ d.month - 1 ], d.day, d.year );
}


bool isCorrectDate ( Date d )
{
	if ( d.year == 0 )
		return false;

	if ( d.month < 1 || d.month > 12 )
		return false;

	if ( d.day < 1 )
		return false;

	if ( d.month == 2 && isLeapYear( d.year ) )
		return d.day < 29;

	else
		return d.day <= DAYS_IN_MONTHS[ d.month - 1 ];
}


bool isLastDayOfMonth ( Date d )
{
	return d.day == DAYS_IN_MONTHS[ d.month - 1 ];
}


Date nextDate ( Date d )
{
	Date result;

	if ( isLastDayOfMonth( d ) )
	{
		result.day = 1;

		if ( d.month == 12 )
		{
			result.year  = d.year + 1;
			result.month = 1;
		}
		else
		{
			result.year = d.year;
			result.month = d.month + 1;
		}
	}
	else
	{
		result = d;
		++ result.day;
	}

	return result;
}


int main ()
{
	Date d = readDate();

	if ( ! isCorrectDate( d ) )
	{
		printf( "Incorrect date\n" );
		return -1;
	}

	printf( "Entered day is: " );
	printDate( d );

	putchar( '\n' );

	printf( "Next day is: " );
	printDate( nextDate( d ) );

	putchar( '\n' );
}
