#include <stdio.h>


int main ()
{
    int x1, x2, x3;
    scanf( "%d %d %d", & x1, &x2, & x3 );

    int * pMin = & x1;
    if ( x2 < * pMin )
        pMin = & x2;
    if ( x3 < * pMin )
        pMin = & x3;

    printf( "Address of minimal value is %p, value = %d\n", pMin, * pMin );

    int replacement;
    scanf( "%d", & replacement );

    * pMin = replacement;

    printf( "%d %d %d\n", x1, x2, x3 );
}
