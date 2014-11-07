#include <stdio.h>

void swap ( int * pData1, int * pData2 )
{
    int temp = * pData1;
    * pData1 = * pData2;
    * pData2 = temp;
}

void scanArray ( int * p, int size )
{
	for ( int i = 0; i < size; i++ )
		scanf( "%d", p + i );
}

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

void selectionSort ( int * p, int size )
{
    for ( int i = 0; i < size - 1; i++ )
    {
        int lowIndex = i;
        for ( int j = i + 1; j < size; j++ )
            if ( p[ j ] < p[ lowIndex ] )
                lowIndex = j;

		swap( p + lowIndex, p + i );
    }
}


int main ()
{
	const int SIZE = 10;
	int data[ SIZE ];

	scanArray( data, SIZE );
	selectionSort( data, SIZE );
	printArray( data, SIZE );

	return 0;
}