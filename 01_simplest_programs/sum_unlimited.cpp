#include <stdio.h>

int main ()
{
    int total = 0;
    while ( ! feof( stdin ) )
    {
        int value = 0;
        scanf( "%d", & value );
    
        total += value;
    }

    printf( "Sum: %d\n", total );

    return 0;
}

