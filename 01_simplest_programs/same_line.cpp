
#include <stdio.h>
#include <math.h>

int main ()
{
    double x1, x2, x3, y1, y2, y3;
    scanf( "%lf %lf", &x1, &y1 );
    scanf( "%lf %lf", &x2, &y2 );
    scanf( "%lf %lf", &x3, &y3 );

    bool result;
    if ( x1 == x2 )
        result = ( x2 == x3 );

    else
    {
        double k = ( y2 - y1 ) / ( x2 - x1 );
        double b = y1 - k * x1;
        result = ( k * x3 + b ) == y3;
    }
    printf( result ? "Yes\n" : "No\n" );
    return 0;
 }