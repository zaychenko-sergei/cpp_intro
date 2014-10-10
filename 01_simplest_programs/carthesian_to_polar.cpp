#include <stdio.h>
#include <math.h>
 
int main ()
{
    double x, y;
    scanf("%lf %lf", &x, &y );

    double ro  = sqrt( x * x + y * y );
    double phi = atan( y / x );
    
    printf("ro = %.3lf, phi = %.3lf\n", ro, phi );
    return 0;
}
