#include <stdio.h>
#include <string.h>

int main ()
{
	char name[ 100 ];
	scanf( "%s", name );

	char greeting1[ 100 ] = "Hello ";
	strcat( greeting1, name );
	printf( "%s\n", greeting1 );

	char * greeting2 = "Hello ";
	char result2[ 100 ];
	strcpy( result2, greeting2 );
	strcat( result2, name );
	printf( "%s\n", result2 );

	char greeting3[] = { 'H', 'e', 'l', 'l', 'l', ' ' };
	char name2[] = { 'J', 'o', 'h', 'n' };

	char result3[ 100 ];
	int greetingSize = sizeof( greeting3 ) / sizeof( char );
	int nameSize     = sizeof( name2 ) / sizeof( char );
	strncpy( result3, greeting3, greetingSize );
	result3[ greetingSize ] = 0;
	strncat( result3 + greetingSize, name2, nameSize );
	result3[ greetingSize + nameSize ] = 0;

	printf( "%s\n", result3 );

	return 0;
}