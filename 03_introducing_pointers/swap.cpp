#include <stdio.h>

void swap ( int * pData1, int * pData2 )
{
    int temp = * pData1;
    * pData1 = * pData2;
    * pData2 = temp;
}

int main ()
{
    int a = 2, b = 3;
    swap( & a, & b );
    printf( "a = %d, b = %d\n", a, b );
    return 0;
}