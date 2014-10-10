#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    time_t currentTime;
    time( & currentTime );

    srand( ( unsigned ) currentTime );
    
    const int numberToGuess = rand() % 100;

    int userInput;
    int steps = 0;
    do
    {
        printf( "Try to guess the number within [ 0 : 99 ]: " );
        scanf( "%d", &userInput );

        ++ steps;

        if ( userInput > numberToGuess )
            printf( "Too big\n" );
        else if ( userInput < numberToGuess )
            printf( "Too small\n" );
    
    } while ( userInput != numberToGuess );

    printf( "Right guess! Completed in %d steps.\n", steps );
    return 0;
}