#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "FitnessDataStruct.h"

FITNESS_DATA fitnessdata[100];
char option;
char line[100];
char filename[100];
char linebuffer[1000];
int count = 0;
char date[11];
char time[6];
char steps[6];
int lowest = 9999;
int highest = 0;
int mean;
int truemean;
int fcount = 0;
char * temp[4];
int streak=0;

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }

int main()
{

    while(1)
    {
  
    printf("Choose one of the following options: \n"
    "A: Specify the filename to be imported\n"
    "B: Display the total number of records in the file\n"
    "C: Find the data and time of the timeslot with the fewest steps\n"
    "D: Find the data and time of the timeslot with the largest number of steps\n"
    "E: Find the mean step count of all the records in the file\n"
    "F: Find the longest continuous period where the step count is above 500 steps\n"
    "Q: Exit\n");
    option = getchar();
    while (getchar() != '\n');

    switch(option)
        {
        case 'A':
        case 'a':
        printf("enter filename: \n");
        fgets(line,100,stdin);
        sscanf(line,"%s",filename);

        FILE *file = fopen(filename, "r");
        if (file == NULL)
            {
            printf("Error opening file\n");
            exit(1);
            }

        while(fgets(linebuffer,100,file)!= NULL)
        {
		    tokeniseRecord(line, ",", 	fitnessdata[count].date, fitnessdata[count].time, steps);
		    fitnessdata[count].steps = atoi(steps);
            count++;
        }
        fclose(file);

            break;
        
        case 'B':
        case'b':
        printf("Total Records: %d\n", count);

            break;
        
        case 'C':
        case 'c':
                for(int i=0;i<count;count++)
                {
                    if(lowest>fitnessdata[i].steps)
                    {
                        lowest = fitnessdata[i].steps;
                    }
                }
                for(int j=0;j<count;j++)
                {
                    if (lowest == fitnessdata[j].steps)
                    {
                    printf("Fewest steps: %s %s\n", fitnessdata[j].date, fitnessdata[j].time);
                    }
                }
            break;
        
        case 'D':
        case 'd': 
                for(int i=0;i<count;count++)
                {
                    if(highest<fitnessdata[i].steps)
                    {
                        highest = fitnessdata[i].steps;
                    }
                }
                for(int j=0;j<count;j++)
                {
                    if (highest == fitnessdata[j].steps)
                    {
                    printf("Largest steps: %s %s\n", fitnessdata[j].date, fitnessdata[j].time);
                    }
                }


            break;

        case 'E':
        case 'e':
                for (int k=0;k<count;k++)
                {
                mean += fitnessdata[k].steps;
                }

            mean = mean / count;
            printf("Mean step count: %d\n", truemean);
            break;
        case 'F':
        case 'f':
                for (int start=0;start<count;start++){
                if (fitnessdata[start].steps > 500)
                {
                    int end = start;
                    while (fitnessdata[end].steps > 500){
                        fcount++;
                        end++;
                    }   
                    end--;

                    if (fcount > streak)
                    {
                        streak = fcount;

                        temp[1] = fitnessdata[start].date;
                        temp[2] = fitnessdata[start].time;
                        temp[3] = fitnessdata[end].date;
                        temp[4] = fitnessdata[end].time;
                    }

                    fcount = 0;
                    start = end + 1;
                }
            }

            printf("Longest period start: %s %s\n", temp[1],temp[2]);
            printf("Longest period end: %s %s\n", temp[3], temp[4]);

            break;

        case 'Q':
        case 'q':
            return 0;
            break;

        default:
        printf("Invalid choice. Try again.\n");
            
        }
    }
    

    
}