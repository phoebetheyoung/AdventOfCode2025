#include <stdio.h>
#include <string.h>
#include <math.h>

const int numberOfNumberRows = 4;
const int numberOfNumbersInRow = 1000;
int numbers[numberOfNumberRows][numberOfNumbersInRow];

char* pointerToNextNumber(char* pointer) {
    int leadingSpaces = strspn(pointer, " ");
    return strchr(pointer + leadingSpaces, ' ');
}

unsigned long long int doSum(int i, char operation) {
    unsigned long long int result = (operation == '+') ? 0 : 1;

    for (int j = 0; j < numberOfNumberRows; j++) {
        int nextNumber = numbers[j][i];
        result = (operation == '+') ? result + nextNumber : result * nextNumber;
    }

    return result;
}

main()
{
    FILE *fptr;
    fptr = fopen("Day06Input.txt", "r");
    char inputLine[3766];
    int rowCounter = -1;
    unsigned long long int sumOfAnswers = 0;
    
    while(fgets(inputLine, 3766, fptr)) {
        ++rowCounter;

        if (atoi(inputLine) > 0) {
            int i = 0;
            char* pointerInInputLine = &inputLine[0];

            while (i < numberOfNumbersInRow) {
                int nextNumber = atoi(pointerInInputLine);
                if (nextNumber == 0) {
                    break;
                }
                numbers[rowCounter][i] = nextNumber;
                pointerInInputLine = pointerToNextNumber(pointerInInputLine);
                ++i;
            }
        } else if (strchr(inputLine, '+') != NULL) {
            int i = 0;

            for (int k = 0; k < strlen(inputLine); k++) {
                char character = inputLine[k];
                
                if (character == '+' || character == '*') {
                    sumOfAnswers += doSum(i, character);
                    ++i;
                }
            }
        }
    }

    fclose(fptr);
    
    printf("Total = %llu", sumOfAnswers);
}