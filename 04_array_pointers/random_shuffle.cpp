#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray ( const int * p, int size )
{
	for ( int i = 0; i < size; i++ )
	{
		if ( i > 0 )
			putchar( ' ' );
		printf( "%d", p[ i ] );
	}
	putchar( '\n' );
}


void swap ( int * pData1, int * pData2 )
{
    int temp = * pData1;
    * pData1 = * pData2;
    * pData2 = temp;
}

void randomShuffle ( int * p, int size, int nRounds = 100 )
{
	for ( int i = 0; i < nRounds; i++ )
	{
		int pos1 = rand() % size;
		int pos2 = rand() % size;

		swap( p + pos1, p + pos2 );
	}
}


int main ()
{
	time_t current;
	time( & current );
	srand( ( unsigned int ) current );

	const int SIZE = 10;
	int data[ SIZE ];
	for ( int i = 0; i < SIZE; i++ )
		data[ i ] = i + 1;

	printArray( data, SIZE );

	randomShuffle( data, SIZE, 1 );

	printArray( data, SIZE );

	randomShuffle( data, SIZE );

	printArray( data, SIZE );

	return 0;
}