#include <stdio.h>
#include <string.h>

int main ()
{
	char tempBuf[ 1024 ], longestBuf[ 1024 ];
	
	int maxLength = 0;

	while ( ! feof( stdin ) )
	{
		gets( tempBuf );
		if ( ! strcmp( tempBuf, "STATUS" ) )
		{
			if ( maxLength > 0 )
				printf( "The longest string seen so far is (%d): %s\n", maxLength, longestBuf );
			else
				printf( "No data collected yet...\n" );
		}

		else
		{
			int len = strlen( tempBuf );
			if ( len > maxLength )
			{
				maxLength = len;
				strcpy( longestBuf, tempBuf );
			}
		}
	}

	if ( maxLength > 0 )
		printf( "The longest string seen is (%d): %s\n", maxLength, longestBuf );
}