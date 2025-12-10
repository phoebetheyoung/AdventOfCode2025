#include <stdio.h>
#include <string.h>

main() // this bit executes
{
    char input[] = "R20\nR10\nL11\n...";
    // https://tools.irvantaufik.me/newline-to-escape/
    // https://www.w3schools.com/c/c_files_read.php

    char direction;
    int amount;
    int dial = 50;
    int count = 0;

    for (int i = 0; i < strlen(input); i++) {
        char character = input[i];

        if (character == '\n') {
            dial += amount * (direction == 'L' ? -1 : 1);
            dial %= 100;

            if (dial == 0) {
                ++count;
            }

            amount = 0;
        } else if (character == 'L' || character == 'R') {
            direction = character;
        } else {
            int digit = character - '0';
            amount = amount * 10 + digit;
        }
    }

    printf("Answer is %d", count);
    printf("\n\nDial ends pointing at %d", dial);
}