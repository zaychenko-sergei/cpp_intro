#include <stdio.h>

int main ()
{
	int numSpaces = 0, numLines = 0, numDigits = 0, numOther = 0;
    
	int c;
	while ( ( c = getchar() ) != EOF )
        switch ( c )
	    {
	        case '0': case '1': case '2': case '3': case '4':
	        case '5': case '6': case '7': case '8': case '9':
	            ++numDigits;
	            break;

	        case ' ':
        	    ++numSpaces;
	            break;

	        case '\n':
	            ++numLines;
	            break;

	        default:
	            ++numOther;
	            break;
	    }
	
	printf( "Spaces: %d, Lines: %d, Digits: %d, Other: %d\n", numSpaces, numLines, numDigits, numOther );
	return 0;
}       
