#include <stdio.h>

void scanArray ( int * p, int size )
{
	for ( int i = 0; i < size; i++ )
		scanf( "%d", p + i );
}

const int * findMinElement ( const int * p, int size )
{
	const int * pResult = p;

	for ( int i = 1; i < size; i++ )
		if ( p[ i ] < * pResult )
			pResult = p + i;

	return pResult;
}

const int * findMaxElement ( const int * p, int size )
{
	const int * pResult = p;

	for ( int i = 1; i < size; i++ )
		if ( p[ i ] > * pResult )
			pResult = p + i;

	return pResult;
}


int main ()
{
	const int SIZE = 10;
	int a[ SIZE ];

	scanArray( a, SIZE );
	const int * pMinElement = findMinElement( a, SIZE );
	const int * pMaxElement = findMaxElement( a, SIZE );
	
	int distance = ( pMinElement <= pMaxElement ) ? ( pMaxElement - pMinElement ) : ( pMinElement - pMaxElement );
	printf( "There are %d cells between minimum and maximum values in the array.\n", distance );
	return 0;
}