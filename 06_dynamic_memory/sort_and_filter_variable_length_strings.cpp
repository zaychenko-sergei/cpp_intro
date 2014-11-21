#include <stdio.h>
#include <string.h>


void readStudentNames ( char ** pStudentNames, int studentsCount )
{
	for ( int i = 0; i < studentsCount; i++ )
	{
		char temp[ 100 ];
		scanf( "%s", temp );

		int length =  strlen( temp );

		char * pName = new char[ length + 1 ];
		strcpy( pName, temp );

		pStudentNames[ i ] = pName;
	}
}


void printStudentNames ( char ** pStudentNames, int studentsCount )
{
	for ( int i = 0; i < studentsCount; i++ )
		printf( "%s\n", pStudentNames[ i ] );
}


void swap ( char ** pString1, char ** pString2 )
{
	char * temp = * pString1;
	* pString1  = * pString2;
	* pString2  = temp;
}


void sortStudentNames ( char ** pStudentNames, int studentsCount )
{
    for ( int i = 0; i < studentsCount - 1; i++ )
    {
        int lowIndex = i;
        for ( int j = i + 1; j < studentsCount; j++ )
            if ( strcmp( pStudentNames[ j ], pStudentNames[ lowIndex ] ) < 0 )
                lowIndex = j;

		swap( pStudentNames + lowIndex, pStudentNames + i );
    }
}


void printStudentsWithIdenticalName ( char ** pStudentNames, int studentsCount )
{	
	for ( int i = 0; i < studentsCount - 1; i++ )
	{
		if ( ! strcmp( pStudentNames[ i ], pStudentNames[ i + 1 ] ) )
		{
			const char * pIdenticalName = pStudentNames[ i ];
			int nIdentical = 1;
			do
			{
				++ i;
				++ nIdentical;

			} while ( ! strcmp( pIdenticalName, pStudentNames[ i + 1 ] ) );

			printf( "There are %d students with name %s\n", nIdentical, pIdenticalName );
		}
	}
}


void releaseStudentNames ( char ** pStudentNames, int studentsCount )
{
	for ( int i = 0; i < studentsCount; i++ )
		delete[] pStudentNames[ i ];

	delete[] pStudentNames;
}


int main ()
{
	int studentsCount;
	printf( "Input number of students: " );
	scanf( "%d", & studentsCount );

	if ( studentsCount <= 0 )
	{
		printf( "Expected a positive number\n" );
		return -1;
	}

	printf( "Input student names:\n" );

	char ** pStudentNames = new char * [ studentsCount ];
	readStudentNames( pStudentNames, studentsCount );

	printStudentsWithIdenticalName( pStudentNames, studentsCount );

	printStudentNames( pStudentNames, studentsCount );

	sortStudentNames( pStudentNames, studentsCount );

	printStudentsWithIdenticalName( pStudentNames, studentsCount );

	releaseStudentNames( pStudentNames, studentsCount );
	return 0;
}