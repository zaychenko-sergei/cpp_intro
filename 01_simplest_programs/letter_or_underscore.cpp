#include <stdio.h>

int main ()
{
	int c;
	while ( ( c = getchar() ) != EOF )
	{
		if ( c >= 'a' && c <= 'z' || c == '_' )
		    putchar( c );
	}
}