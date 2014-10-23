#include <stdio.h>
    
int power ( int base, int n )
{
    if ( base == 2 )
        return 1 << n;

    int p = 1;
    int i;
    for ( i = 1; i <= n; ++i )
        p *= base;
    return p;
}
    
int main ()
{
    for ( int i = 0; i < 31; ++i )
        printf("2^%d = %d\n", i, power( 2, i ) );

    for ( int i = 0; i < 20; ++i )
        printf("3^%d = %d\n", i, power( 3, i ) );
}