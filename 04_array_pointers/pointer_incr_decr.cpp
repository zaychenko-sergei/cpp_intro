#include <stdio.h>

int main ()
{
	int data[] = { 1, 2, 3, 4, 5 };
	int size = sizeof( data ) / sizeof( int );

	int * pDataLast = data + size - 1;

	int * p1 = data;
	while ( p1 <= pDataLast )
	{
		printf( "%d ", * p1 );
		++ p1;
	}

	putchar( '\n' );

	int * p2 = pDataLast;
	while ( p2 >= data )
	{
		printf( "%d ", * p2 );
		-- p2;
	}

	return 0;
}
