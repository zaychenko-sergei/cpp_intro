#include <stdio.h>
#include <memory.h>

void swap ( int * pData1, int * pData2 )
{
    int temp = * pData1;
    * pData1 = * pData2;
    * pData2 = temp;
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
	int nUsedData = 0;
	int nAllocatedData = 2;
	int * pData = new int[ nAllocatedData ];

	while ( ! feof( stdin ) )
	{
		int value;
		int res = scanf( "%d", & value );
		if ( res != 1 )
			break;

		if ( nUsedData == nAllocatedData )
		{
			printf( "Growing from %d to %d\n", nAllocatedData, nAllocatedData * 2 );

			int * pNewData = new int[ nAllocatedData * 2 ];
			memcpy( pNewData, pData, sizeof( int ) * nAllocatedData );
			delete[] pData;
			pData = pNewData;
			nAllocatedData *= 2;
		}

		pData[ nUsedData++ ] = value;
	}

	reverseArray( pData, nUsedData );
	printArray( pData, nUsedData );

	printf( "Finally, %d values used of %d total allocated\n", nUsedData, nAllocatedData );

	delete[] pData;
	return 0;
}