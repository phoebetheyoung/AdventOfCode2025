#include <stdio.h>
#include <string.h>
#include <math.h>

int min(int a, int b) {
    return (a > b) ? b : a;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

main()
{
    FILE *fptr;
    fptr = fopen("Day04Input.txt", "r");
    char inputLine[141];
    int rows[139][139];
    int countOfRolls = 0;
    int rowCounter = -1;
    
    while(fgets(inputLine, 141, fptr)) {
        ++rowCounter;

        for (int k = 0; k < strlen(inputLine); k++) {
            rows[rowCounter][k] = (inputLine[k] == '@') ? 1 : 0;
        }
    }

    fclose(fptr);

    for (int i = 0; i < sizeof(rows) / sizeof(rows[0]); i++) {
        int length = sizeof(rows[0]) / sizeof(rows[0][0]);

        for (int j = 0; j < length; j++) {
            if (rows[i][j] == 1) {
                int neighbourRolls = -1; // original roll counted to bring this to 0
    
                for (int a = max(i - 1, 0); a <= min(i + 1, length - 1); a++) {
                    for (int b = max(j - 1, 0); b <= min(j + 1, length - 1); b++) {
                        neighbourRolls += rows[a][b];
                    }
                }
    
                if (neighbourRolls < 4) {
                    ++countOfRolls;
                }
            }
        }
    }
    
    printf("Total = %d", countOfRolls);
}