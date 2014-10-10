#include <stdio.h>

int main ()
{
    double amountUAH, rateUAH2USD;
    scanf( "%lf %lf", & amountUAH, & rateUAH2USD );
    printf( "In USD: %.2lf\n", amountUAH / rateUAH2USD );
}
