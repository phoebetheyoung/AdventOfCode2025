#include <stdio.h>
#include <string.h>
#include <math.h>

main()
{
    FILE *fptr;
    fptr = fopen("Day05Input.txt", "r");
    char inputLine[33];
    long long int ranges[185][2];
    int rowCounter = -1;
    int countOfFreshIngredients = 0;
    int rangesDone = 0;
    
    while(fgets(inputLine, 33, fptr)) {
        ++rowCounter;

        if (inputLine[0] == '\n') {
            rangesDone = 1;
        }

        if (rangesDone == 0) {
            long long int constructNumber = 0;

            for (int k = 0; k < strlen(inputLine); k++) {
                char character = inputLine[k];

                if (character == '-') {
                    ranges[rowCounter][0] = constructNumber;
                    constructNumber = 0;
                } else if (character == '\n') {
                    ranges[rowCounter][1] = constructNumber;
                } else {
                    int digit = character - '0';
                    constructNumber = constructNumber * 10 + digit;
                }
            }
        } else {
            long long int ingredient = 0;

            for (int k = 0; k < strlen(inputLine); k++) {
                char character = inputLine[k];

                if (character != '\n') {
                    int digit = character - '0';
                    ingredient = ingredient * 10 + digit;
                }
            }

            for (int i = 0; i < sizeof(ranges) / sizeof(ranges[0]); i++) {
                long long int minOfRange = ranges[i][0];
                long long int maxOfRange = ranges[i][1];

                if (minOfRange <= ingredient && ingredient <= maxOfRange) {
                    ++countOfFreshIngredients;
                    break;
                }
            }
        }
    }

    fclose(fptr);
    
    printf("Total = %d", countOfFreshIngredients);
}