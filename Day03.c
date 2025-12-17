#include <stdio.h>
#include <string.h>
#include <math.h>

main()
{
    FILE *fptr;
    fptr = fopen("Day03Input.txt", "r");
    char inputLine[102];
    int sumOfJoltages = 0;
    
    while(fgets(inputLine, 102, fptr)) {
        int firstDigit = -1;
        int secondDigit = -1;

        for (int i = 0; i < strlen(inputLine) - 2; i++) {
            int digit = inputLine[i] - '0';
            int nextDigit = inputLine[i + 1] - '0';

            if (digit > firstDigit) {
                firstDigit = digit;
                secondDigit = nextDigit;
            } else if (nextDigit > secondDigit) {
                secondDigit = nextDigit;
            }
        }

        sumOfJoltages += firstDigit * 10 + secondDigit;
    }

    fclose(fptr);
    
    printf("Total = %d", sumOfJoltages);
}