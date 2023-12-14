#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}

int isValidDataFormat(const char *input) {
    int comma_count = 0;
    int length = strlen(input);

    if (length < 20 || length > 22) 
    {
        return 1; 
    }

    for (int i = 0; i < length; i++) 
    {
        if ((i == 11 || i == 17) && input[i] != ',') 
        {
            return 1;
        }
          if ((i == 5 || i == 8) && input[i] != '-') 
        {
            return 1;
        }
          if ((i == 14) && input[i] != ':') 
        {
            return 1;
        }

        if((i!=5 && i!=8 && i!=14 && i!=11 && i!=17) && !isdigit(input[i]))
        {
            return 1;
        }
    }

    return 0; 
}

void sortBySteps(FitnessData data[], int size)
{
    FitnessData temp;
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (data[j].steps < data[j + 1].steps) 
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}


int main() 
{
    FitnessData fitness_data[200];
    char line[100];
    char date[11], time[6];
    int steps;
    char filename[100];
    int count = 0;

    printf("Enter filename:");
    scanf("%s",filename);

    FILE *file = fopen(filename,"r");
     if (file == NULL)
            {
            printf("Error: invalid file\n");
            return 1;
            }

    while(fgets(line,100,file) !=NULL)
    {
        line[strcspn(line, "\n")] = 0;
        if (!isValidDataFormat(line)) 
        {
            printf("Error: invalid data format\n");
            fclose(file);
            return 1;
        }
        tokeniseRecord(line, ',', date, time, &steps);
        strcpy(fitness_data[count].date, date);
        strcpy(fitness_data[count].time, time);
        fitness_data[count].steps = (steps);
        count++;


    }
    fclose(file);

    sortBySteps(fitness_data, count);

    strcat(filename, ".tsv");
    file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error opening file for writing\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\t%s\t%d\n", fitness_data[i].date, fitness_data[i].time, fitness_data[i].steps);
    }

    fclose(file);
    printf("Sorted data has been written to %s\n", filename);

    return 0;
    
}