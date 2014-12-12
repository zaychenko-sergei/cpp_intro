#include <stdio.h>
#include <assert.h>


enum LabStatus
{
	LS_Not_Started,
	LS_In_Progress,
	LS_Reviewed,
	LS_Defended
};


const char * labStatusToString ( LabStatus l )
{
	switch ( l )
	{
		case LS_Not_Started:	return "Not started";
		case LS_In_Progress:    return "In progress";
		case LS_Reviewed:       return "Reviewed";
		case LS_Defended:       return "Defended";

		default:
			assert( ! "Unknown lab status" );
			return nullptr;
	}
}


const int NUM_LABS = 3;


struct StudentLabs
{
	const char * name;
	LabStatus labStatus[ NUM_LABS ];
};


bool hasPassedLabs ( const StudentLabs & sl )
{
	for ( int i = 0; i < NUM_LABS; i++ )
		if ( sl.labStatus[ i ] != LS_Defended )
			return false;

	return true;
}


void reportStudentStatus ( const StudentLabs & sl )
{
	printf( "Student %s%s lab data: ", sl.name, hasPassedLabs( sl ) ? " PASSED" : "" );
	for ( int i = 0; i < NUM_LABS; i++ )
		printf( "%d - %s; ", i + 1, labStatusToString( sl.labStatus[ i ] ) );
	putchar( '\n' );
}


void startWorkingOnLab ( StudentLabs & sl, int labIndex )
{
	assert( labIndex >= 0 && labIndex < NUM_LABS );
	sl.labStatus[ labIndex ] = LS_In_Progress;
}

void reviewLab ( StudentLabs & sl, int labIndex )
{
	assert( labIndex >= 0 && labIndex < NUM_LABS );
	sl.labStatus[ labIndex ] = LS_Reviewed;
}

void defendLab ( StudentLabs & sl, int labIndex )
{
	assert( labIndex >= 0 && labIndex < NUM_LABS );
	sl.labStatus[ labIndex ] = LS_Defended;
}

int main ()
{
	StudentLabs sl = { "Ivanov", { LS_Not_Started, LS_Not_Started, LS_Not_Started } };
	reportStudentStatus( sl );

	for ( int i = 0; i < NUM_LABS; i++ )
	{
		startWorkingOnLab( sl, i );
		reportStudentStatus( sl );

		reviewLab( sl, i );
		reportStudentStatus( sl );

		defendLab( sl, i );
		reportStudentStatus( sl );
	}

}