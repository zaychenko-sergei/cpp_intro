#include <stdio.h>
#include <memory.h>

int main ()
{
	const int NUM_LETTERS = 26;
	int letterCounters[ NUM_LETTERS ];
	memset( letterCounters, 0, sizeof( int ) * NUM_LETTERS );

	int c;
	while ( ( c = getchar() ) != EOF )
	{
	    if ( c >= 'A' && c <= 'Z' )
	        c += 'a' - 'A';
	    if ( c >= 'a' && c <= 'z' )
	        letterCounters[ c - 'a' ]++;
	}

	for ( int i = 0; i < NUM_LETTERS; i++ )
		if ( letterCounters[ i ] )
			printf( "Letter '%c' was typed %d times\n", i + 'a', letterCounters[ i ] );

	return 0;
}
