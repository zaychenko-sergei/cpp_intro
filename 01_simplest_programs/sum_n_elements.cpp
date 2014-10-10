#include <stdio.h>

int main ()
{
    int count = 0;
    scanf( "%d", & count );

    if ( count <= 0 )
    {
        printf( "Error: count must be positive\n" );
        return -1;
    }

    int total = 0;
    for ( int i = 0; i < count; i++ )
    {
        int value;
        scanf( "%d", & value );
        total += value;
    }

    printf( "Sum: %d\n", total );
    return 0;
}