#include <stdio.h>
#include <math.h>

bool inputPoint ( double * pX, double * pY )
{
    int res = scanf( "%lf %lf", pX, pY );
    return ! feof( stdin ) && res == 2;
}

double getDistance ( double xA, double yA, double xB, double yB )
{
    return sqrt( ( xB - xA ) * ( xB - xA ) + ( yB - yA ) * ( yB - yA ) );
}

int main ()
{
    double path = 0.0;

    double xPrev, yPrev;
    if ( ! inputPoint( & xPrev, & yPrev ) )
    {
        printf( "Error: expected double point coordinates (x,y)\n" );
        return -1;
    }

    double xNew, yNew;
    while ( inputPoint( & xNew, & yNew ) )
    {
        path += getDistance( xPrev, yPrev, xNew, yNew );
        xPrev = xNew;
        yPrev = yNew;
    }

    printf( "Total path - %lf\n", path );
    return 0;
}