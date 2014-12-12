#include <stdio.h>
#include <assert.h>

enum Season
{
	Season_Invalid,
	Season_Winter,
	Season_Spring,
	Season_Summer,
	Season_Autumn
};

Season getSeasonByMonth ( int monthIndex )
{
	switch ( monthIndex )
	{
		case 1: case  2: case 12: return Season_Winter;
		case 3: case  4: case  5: return Season_Spring;
		case 6: case  7: case  8: return Season_Summer;
		case 9: case 10: case 11: return Season_Autumn;

		default:
			assert( ! "Unexpected season name" );
			return Season_Invalid;
	}
}

const char * SeasonToStr ( Season s )
{
	switch ( s )
	{
		case Season_Winter: return "Winter";
		case Season_Spring: return "Spring";
		case Season_Summer: return "Summer";
		case Season_Autumn: return "Autumn";

		default:
			assert( ! "Unexpected season" );
			return nullptr;
	}
}

void walk ( Season s, bool hasHat )
{
	if ( s == Season_Winter && ! hasHat )
		printf( "You forgot hat, it is cold outside.\n" );
	else if ( s == Season_Summer && hasHat )
		printf( "It will be too hot in a hat, it is warm outside.\n" );
	else
		printf( "Have a nice walk\n" );
}

int main ()
{
	while ( true )
	{
		printf( "Input month [1:12] or 0 to quit: " );
		int monthIndex;
		scanf( "%d", & monthIndex );

		if ( monthIndex == 0 )
			break;

		else if ( monthIndex >= 1 && monthIndex <= 12 )
		{
			printf( "Do you wear hat today (1 for yes)? " );
			int hasHat;
			scanf( "%d", & hasHat );
			walk( getSeasonByMonth( monthIndex ), hasHat == 1 );
		}

		else
			printf( "Error: wrong month index\n" );

	}
}