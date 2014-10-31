
#include <stdio.h>
#include <math.h>
#include <assert.h>

const int QE_SOLVED_OK     = 0;
const int QE_ZERO_A_COEFF  = 1;
const int QE_NO_REAL_ROOTS = 2;

int solveQuadtaticEquation ( double a, double b, double c, double * pRoot1, double * pRoot2 )
{
    if ( a == 0 )
        return QE_ZERO_A_COEFF;

    double d = b * b - 4. * a * c;
    if ( d < 0 )
        return QE_NO_REAL_ROOTS;

    else if ( d == 0 )
        * pRoot1 = * pRoot2 = -b / 2 / a;

    else
    {
        double dRoot = sqrt( d );
        * pRoot1 = ( -b + dRoot ) / 2 / a;
        * pRoot2 = ( -b - dRoot ) / 2 / a;
    }

    return QE_SOLVED_OK;
}


int main ()
{
    double a, b, c;
    printf( "Input a b c: " );
    scanf( "%lf %lf %lf", &a, &b, &c );

    double root1, root2;
    int res = solveQuadtaticEquation( a, b, c, & root1, & root2 );
    switch ( res )
    {
        case QE_SOLVED_OK:
             printf( "Roots: %lf %lf\n", root1, root2 );
             return 0;

        case QE_NO_REAL_ROOTS:
            printf( "No real roots\n" );
            return -1;

        case QE_ZERO_A_COEFF:
            printf( "Not a quadratic equation\n" );
            return -1;

        default:
            assert( 0 );
            return -1;
    }
}