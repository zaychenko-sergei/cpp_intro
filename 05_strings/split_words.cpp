#include <stdio.h>
#include <string.h>

int main ()
{
	char buf[] = "Will expel all lazy students";
	char* p = strtok( buf, " " );
	printf( "%s\n", p );
	do
	{
		p = strtok( 0, " " );
		if ( p )
		    printf( "%s\n", p );
		
	} while ( p );

	return 0;
}       
