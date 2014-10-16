#include <stdio.h>
#include <math.h>


double getDistance ( double xA, double yA, double xB, double yB )
{
	return sqrt( ( xB - xA ) * ( xB - xA ) + ( yB - yA ) * ( yB - yA ) );
}


double getTriangleArea ( double side1, double side2, double side3 )
{
    double halfPerimeter = ( side1 + side2 + side3 ) / 2.0;
	return  sqrt(
		halfPerimeter * 
		( halfPerimeter - side1 ) * 
		( halfPerimeter - side2 ) * 
		( halfPerimeter - side3 ) );
}


bool checkTriangleRule ( double side1, double side2, double side3 )
{
	return ( side1 < ( side2 + side3 ) ) &&
		   ( side2 < ( side1 + side3 ) ) &&
		   ( side3 < ( side1 + side2 ) );
}


int main ()
{
	double x1, y1, x2, y2, x3, y3;
	scanf( "%lf %lf %lf %lf %lf %lf", & x1, & y1, & x2, & y2, & x3, & y3 );

	double side12 = getDistance( x1, y1, x2, y2 );
	double side13 = getDistance( x1, y1, x3, y3 );
	double side23 = getDistance( x2, y2, x3, y3 );

	if ( ! checkTriangleRule( side12, side13, side23 ) )
	{
		printf( "Not a triangle.\n" );
		return -1;
	}

	printf( "Triangle area is - %lf\n", getTriangleArea( side12, side13, side23 ) );
	return 0;
}