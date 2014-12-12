#include <stdio.h>
#include <assert.h>


enum TrafficLight
{
	TL_Off,
	TL_Red,
	TL_Red_Yellow,
	TL_Green,
	TL_Green_Blinking,
	TL_Yellow,
	TL_YellowBlinking,

	TL_Total
};


const char * TrafficLight2Str ( TrafficLight l )
{
	switch ( l )
	{
		case TL_Off:				return "Off";
		case TL_Red:				return "Red";
		case TL_Red_Yellow:			return "Red & Yellow";
		case TL_Green:				return "Green";
		case TL_Green_Blinking:		return "Blinking green";
		case TL_Yellow:				return "Yellow";
		case TL_YellowBlinking:		return "Blinking yellow";

		default:
			assert( ! "Unknown traffic color" );
			return nullptr;
	}
}

bool IsManagingTraffic ( TrafficLight l )
{
	switch ( l )
	{
		case TL_Off:
		case TL_YellowBlinking:
			return false;

		default:
			return true;
	}
}


bool IsTrafficAllowed ( TrafficLight l )
{
	switch ( l )
	{
		case TL_Green:
		case TL_Green_Blinking:
			return true;

		default:
			return false;
	}
}


void printStatus ( TrafficLight l )
{
	bool canMove = ! IsManagingTraffic( l ) || IsTrafficAllowed( l );
	printf( "Traffic light is %s. You %s move.\n", TrafficLight2Str( l ), canMove ? "can" : "cannot" );
}


TrafficLight nextTrafficLight ( TrafficLight l )
{
	static TrafficLight s_nextLights[] = {
		/* TL_Off            => */  TL_Off,
		/* TL_Red            => */  TL_Red_Yellow,
		/* TL_Red_Yellow     => */  TL_Green,
		/* TL_Green          => */  TL_Green_Blinking,
		/* TL_Green_Blinking => */  TL_Yellow,
		/* TL_Yellow         => */  TL_Red,
		/* TL_YellowBlinking => */  TL_YellowBlinking
	};

	static_assert( sizeof( s_nextLights ) / sizeof( TrafficLight ) == TL_Total, "Enum inconsistent with array" );

	return s_nextLights[ l ];
}


int main ()
{
	TrafficLight l = TL_Off;

	printStatus( l );
	printf( "Press any key to enable traffic..." );
	getchar();

	l  = TL_Red;

	while ( true )
	{
		printStatus( l );

		printf( "Input 'q' to quit, 'e' to turn on/off, 'b' to toggle blinking mode, any other key for next state\n" );
		switch ( getchar() )
		{
			case 'q':
				return 0;

			case 'e':
				l = ( l == TL_Off ) ? TL_Yellow : TL_Off;
				break;

			case 'b':
				l = ( l == TL_Off ) ? TL_Off : ( ( l == TL_YellowBlinking ) ? TL_Yellow : TL_YellowBlinking );
				break;

			default:
				l = nextTrafficLight( l );
				break;
		}
	}
}