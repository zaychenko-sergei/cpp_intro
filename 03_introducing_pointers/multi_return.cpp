#include <stdio.h>

void divide ( int numerator, int denominator, int * pDivided, int * pModulo )
{
    * pDivided = numerator / denominator;
    * pModulo  = numerator % denominator;
}

int main ()
{
    int x, y;
    scanf( "%d %d", & x, & y );

    int div, mod;
    divide( x, y, & div, & mod );

    printf( "Div - %d, Mod - %d\n", div, mod );
}