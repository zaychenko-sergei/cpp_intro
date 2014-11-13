#include <stdio.h>
 
void printNamesOnLetter ( const char** pNames, int _nNames, char firstLetter )
{
	for ( int i = 0; i < _nNames; i++ )
	{
		const char * pCurrent = pNames[ i ];
		if ( pCurrent[ 0 ] == firstLetter )
 		    printf( "%s\n", pCurrent );
 		pCurrent++;
 	}
}
 
int main ()
{
 	const char* lastNames [] = { "Smith", "Jones", "Collins", "Wright", "Carpenter" };
	int nNames = sizeof( lastNames ) / sizeof( void * );
 	printNamesOnLetter( lastNames, nNames, 'C' );
	return 0;
}
