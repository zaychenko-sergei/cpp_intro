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

void reverseArray ( int * p, int size )
{
	for ( int i = 0, k = size - 1; i < k; i++, k-- )
		swap( p + i, p + k );

}

int main ()
{
	const int SIZE = 10;
	int a[ SIZE ];

	scanArray( a, SIZE );
	reverseArray( a, SIZE );
	printArray( a, SIZE );

	return 0;
}