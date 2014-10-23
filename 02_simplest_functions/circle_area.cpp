#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

double getDistance ( double xA, double yA, double xB, double yB )
{
	return sqrt( ( xB - xA ) * ( xB - xA ) + ( yB - yA ) * ( yB - yA ) );
}

double circleArea ( double radius )
{
	return M_PI * radius * radius;
}

int main ()
{
	double xCenter, yCenter, xPoint, yPoint;
	scanf( "%lf %lf %lf %lf", & xCenter, & yCenter, & xPoint, & yPoint );

	double radius = getDistance( xCenter, yCenter, xPoint, yPoint );
	printf( "Circle area - %lf\n", circleArea( radius ) );
	return 0;
}