#include <stdio.h>
#include <math.h>


const int NUM_LABS   = 4;
const int NUM_TESTS  = 2;
const float MISSED_LECTURE_PENALTY = 2.f;
const float LAB_WEIGHT = 0.75;
const float TEST_WEIGHT = 0.25;


struct StudentScore
{
	const char* m_StudentFIO;
	int m_NumMissedLectures;
	int m_LabMarks[ NUM_LABS ];
	int m_TestMarks[ NUM_TESTS ];
};


float calculateLabPercentage ( const StudentScore* pScore )
{
	int labTotal = 0;
	for ( int i = 0; i < NUM_LABS; i++ )
		labTotal += pScore->m_LabMarks[ i ];
	return ( float ) labTotal / ( float ) ( NUM_LABS * 5 );
}


float calculateTestPercentage ( const StudentScore* pScore  )
{
	int testTotal = 0;
	for ( int i = 0; i < NUM_TESTS; i++ )
	testTotal += pScore->m_TestMarks[ i ];
	return ( float ) ( testTotal ) / (float ) ( NUM_TESTS * 5 );
}


float calculateMissedLecturesPenalty ( const StudentScore * pScore )
{
	return pScore->m_NumMissedLectures * MISSED_LECTURE_PENALTY / 100.f;
}


int calcFinalStudentMark ( const StudentScore* pScore )
{
	float weightedPercentage = 
		calculateLabPercentage( pScore )  * LAB_WEIGHT +
		calculateTestPercentage( pScore ) * TEST_WEIGHT -
		calculateMissedLecturesPenalty( pScore );

	return ( int ) ( weightedPercentage * 100 );
}


int main ()
{
	StudentScore students[] =
	{ 
	    { "Botankin",   0, { 5, 5, 5, 5 }, { 5, 5 } },
        { "Skachkov",   4, { 5, 4, 3, 5 }, { 3, 5 } },
        { "Tugodumov",  2, { 3, 4, 3, 3 }, { 3, 4 } },
	    { "Nehodishko", 7, { 2, 2, 3, 2 }, { 2, 3 } }
	};


	int numStudents = sizeof( students ) / sizeof ( StudentScore );
	for ( int i = 0; i < numStudents; i++ )
		printf("Student %s\t%d\n", students[ i ].m_StudentFIO, calcFinalStudentMark( students + i ) );
}


