
#include <stdio.h>
#include <math.h>

int main ()
{
    double a, b, c;
    printf( "Input a b c: " );
    scanf( "%lf %lf %lf", &a, &b, &c );

    if ( a <= 0 )
        printf( "Not a quadratic equation\n" );

    else
    {
        double d = b * b - 4. * a * c;
        if ( d < 0 )
            printf( "No real roots\n" );

        else if ( d == 0 )
        {
            double x = - b / 2 / a;
            printf( "Single root: %lf\n", x );
        }

        else if ( d > 0 )
        {
            double dRoot = sqrt( d );
            double x1 = ( -b + dRoot ) / 2 / a;
            double x2 = ( -b - dRoot ) / 2 / a;
            printf( "Two roots: %lf %lf\n", x1, x2 );
        }
    }

    return 0;
}