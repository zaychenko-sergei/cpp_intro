
#include <stdio.h>

void makeUpperCase ( char * s )
{
    for ( int i = 0; s[ i ]; i++ )
        if ( s[ i ] >= 'a' && s[ i ] <= 'z' )
            s[ i ] += 'A' - 'a';
}

void makeLowerCase ( char * s )
{
    for ( int i = 0; s[ i ]; i++ )
        if ( s[ i ] >= 'A' && s[ i ] <= 'Z' )
            s[ i ] -= 'A' - 'a';
}

int main ()
{
    char buf1[ 100 ], buf2[ 100 ];
    gets( buf1 );
    gets( buf2 );

    makeUpperCase( buf1 );
    makeLowerCase( buf2 );

    printf( "Upper case: %s\n", buf1 );
    printf( "Lower case: %s\n", buf2 );

    return 0;
}