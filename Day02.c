#include <stdio.h>
#include <string.h>
#include <math.h>

long long int getSumOfInvalidIds(long long int lowerBound, long long int upperBound) {
    long long int count = 0;
    
    for (long long int id = lowerBound; id <= upperBound; id++) {
        int length = ceil(log10(id));
        if (length / 2 != floor(length / 2)) {
            break;
        }
        
        long long int powerOfTen = 1;
        for (long long int j = 1; j <= length / 2; j++) {
            powerOfTen *= 10;
        }
        
        long long int potentialRepeat = floor(id / powerOfTen);
        if (id == potentialRepeat * (powerOfTen + 1)) {
            count += id;
        }
    }
    
    return count;
}

main()
{
    FILE *fptr;
    fptr = fopen("Day02Input.txt", "r");
    char input[532];
    
    fgets(input, 532, fptr);
    fclose(fptr);

    long long int sumOfInvalidIds = 0;
    long long int lowerBound, upperBound;
    long long int readingNumber = 0;
    
    for (int i = 0; i < strlen(input); i++) {
        char character = input[i];

        if (character == ',') {
            upperBound = readingNumber;

            sumOfInvalidIds += getSumOfInvalidIds(lowerBound, upperBound);

            lowerBound = 0;
            upperBound = 0;
            readingNumber = 0;
        } else if (character == '-') {
            lowerBound = readingNumber;
            readingNumber = 0;
        } else {
            int digit = character - '0';
            readingNumber = readingNumber * 10 + digit;
        }
    }

    upperBound = readingNumber;
    sumOfInvalidIds += getSumOfInvalidIds(lowerBound, upperBound);

    printf("Total = %lld", sumOfInvalidIds);
}