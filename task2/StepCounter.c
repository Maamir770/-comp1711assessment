#include <stdlib.h>
#include<string.h>
#include "FitnessDataStruct.h"

int main()
{
    char option;
    printf("Choose one of the following options: \n"
    "A: Specify the filename to be imported\n"
    "B: Display the total number of records in the file\n"
    "C: Find the data and time of the timeslot with the fewest steps\n"
    "D: Find the data and time of the timeslot with the largest number of steps\n"
    "E: Find the mean step count of all the records in the file\n"
    "F: Find the longest continuous period where the step count is above 500 steps\n"
    "Q: Exit\n");
    scanf("%c", option);

    switch(option)
    {
        case 'A':

            break;
        
        case 'B':

            break;
        
        case 'C':

            break;
        
        case 'D':

            break;

        case 'E':

            break;

        case 'F':

            break;

        case 'Q':
            exit;
            break;

        default:
            
    }

    return 0;
}