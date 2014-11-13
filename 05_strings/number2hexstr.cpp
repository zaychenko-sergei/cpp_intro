#include <stdio.h>

int main ()
{
    int decimal;
    printf( "Input decimal number: ");
    scanf( "%d", &decimal );

    const int BASE = 16;
    
    const int MAX_HEX_WIDTH = 8;
    char hexBuf[ 8 + 1 /* zero terminator */ ];
    hexBuf[ MAX_HEX_WIDTH ] = 0;
    int i = MAX_HEX_WIDTH - 1;

    do
    {
        int temp = decimal % BASE;
        decimal /= BASE;
        hexBuf[ i-- ] = ( temp < 10 ) ? ( '0' + temp ) : ( 'A' + temp - 10 );
    
    } while ( decimal );
    
    printf( "%s\n", hexBuf + i + 1 );
	return 0;
}
