#include <stdio.h>
#include <time.h>
#include <math.h>

double clock2Seconds ( clock_t _start, clock_t _end )
{
	clock_t diff = _end - _start;
	return diff / ( double ) CLOCKS_PER_SEC;
}

int main ()
{
	clock_t clock1 = clock();

	{
		double total = 0;
		for ( int i = 0; i < 100000000; i++ )
			total += sin( 0.001 * i );
	}

	clock_t clock2 = clock();

	{
		double total = 0;
		for ( int i = 0; i < 100000000; i++ )
			total += sin( 0.001 * i ) * cos( 0.001 * i );
	}

	clock_t clock3 = clock();
	
	printf( "Task 1: %.3lf sec.\n", clock2Seconds( clock1, clock2 ) );
	printf( "Task 2: %.3lf sec.\n", clock2Seconds( clock2, clock3 ) );
}