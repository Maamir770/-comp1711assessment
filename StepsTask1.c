#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here
int count = 0;
char linebuffer[100];
FITNESS_DATA fitnessdata[100];
char date[11];
char time[6];
char steps[6];
int i;

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

// Complete the main function
int main() 
{
    FILE *file = fopen("FitnessData_2023.csv","r");
    while(fgets(linebuffer,100,file) !=NULL)
    {
        tokeniseRecord(linebuffer, ",", date, time, steps);
        strcpy(fitnessdata[count].date, date);
        strcpy(fitnessdata[count].time, time);
        fitnessdata[count].steps = atoi(steps);
        count++;
    }
    printf("number of records in file: %d\n",count);
    for(i=0;i<3;i++)
    {
        printf("%s/%s/%d\n", fitnessdata[i].date, fitnessdata[i].time, fitnessdata[i].steps);
    }
    return 0;

}