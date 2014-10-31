#include <stdio.h>


bool isOdd ( int x )
{
    return ( x % 2 ) != 0;
}


int * chooseSmallerOdd ( int * pX, int * pY )
{
    bool oddX = isOdd( * pX );
    bool oddY = isOdd( * pY );
    if ( oddX && oddY )
        return ( * pX <= * pY ) ? pX : pY;

    else if ( oddX )
        return pX;

    else if ( oddY )
        return pY;

    else
        return nullptr;
}


int main ()
{
    int a, b;
    scanf( "%d %d", & a, & b );

    int * pSmallerOdd = chooseSmallerOdd( & a, & b );
    if ( ! pSmallerOdd )
    {
        printf( "Numbers are not odd\n" );
        return -1;
    }

    ( * pSmallerOdd ) ++;

    printf( "Incremeting smaller odd value:\n%d %d\n", a, b );
    return 0;
}

