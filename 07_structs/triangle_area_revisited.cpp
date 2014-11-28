#include <stdio.h>
#include <math.h>


struct Point
{
	double x;
	double y;
};


void readPoint ( Point * pPoint )
{
	scanf( "%lf %lf", &( pPoint->x ), &( pPoint->y ) );
}


double getDistance ( Point a, Point b )
{
	double xDiff = b.x - a.x;
	double yDiff = b.y - a.y;
    return sqrt( xDiff * xDiff + yDiff * yDiff );
}


struct Triangle
{
	Point p1, p2, p3;
};


void readTriangle ( Triangle * pTriangle )
{
	readPoint( & ( pTriangle->p1 ) );
	readPoint( & ( pTriangle->p2 ) );
	readPoint( & ( pTriangle->p3 ) );
}


void calculateTriangleSides ( const Triangle * pTriangle, double * pSide12, double * pSide13, double * pSide23 )
{
    * pSide12 = getDistance( pTriangle->p1, pTriangle->p2 );
    * pSide13 = getDistance( pTriangle->p1, pTriangle->p3 );
    * pSide23 = getDistance( pTriangle->p2, pTriangle->p3 );
}


bool checkTriangleRule ( const Triangle * pTriangle )
{
    double side12, side13, side23;
	calculateTriangleSides( pTriangle, & side12, & side13, & side23 );

    return ( side12 < ( side13 + side23 ) ) &&
           ( side13 < ( side12 + side23 ) ) &&
           ( side23 < ( side12 + side13 ) );
}


double getTriangleArea ( const Triangle * pTriangle )
{
    double side12, side13, side23;
	calculateTriangleSides( pTriangle, & side12, & side13, & side23 );

    double halfPerimeter = ( side12 + side13 + side23 ) / 2.0;
    return  sqrt(
        halfPerimeter * 
        ( halfPerimeter - side12 ) * 
        ( halfPerimeter - side13 ) * 
        ( halfPerimeter - side23 ) );
}


int main ()
{
	Triangle t;
	readTriangle( & t );

	if ( ! checkTriangleRule( & t ) )
    {
        printf( "Not a triangle.\n" );
        return -1;
    }

    printf( "Triangle area is %lf\n", getTriangleArea( & t ) );
    return 0;
}