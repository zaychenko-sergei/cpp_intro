#include <stdio.h>

int main ()
{
	int i, k;
	for ( i = 0; i < 10; i++ )
	{
		for ( k = 0; k < 10; k++ )
		    printf( "%d*%d=%d\t", i, k, i * k );
		putchar( '\n' );
	}
	
	return 0;
}