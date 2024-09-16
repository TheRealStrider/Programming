#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int row = 1;

    // Printing the multiplication table of a 12x12 square
    for (int i = 1, j = 1; row < 13; i++) {
        j = (1 + i) * row;
        if (i == 1 && i * row < 10) {
            printf(" %d", i * row);
        }
        else {
            printf("%d", i * row);
        }

        if (j < 10) {
            printf("   ");
        }
        else if (j < 100) {
            printf("  ");
        }
        else {
            printf(" ");
        }

        if (i == 12) {
            printf("\n");
            row++;
            i = 0;
        }
    }

    int guess = 0;
    srand(time(NULL)); // Seeding random number so it is always random
    int guessAnswer = (rand() % 10) + 1;
    printf("\n");
    do {
        printf("Enter your guess (1-10):\n");
        scanf("%d", &guess);

        if (guess < guessAnswer) {
            printf("Too low!\n");
        }
        else if (guess > guessAnswer) {
            printf("Too high!\n");
        }
        else {
            printf("You guessed it!\n");
        }
    } while (guess != guessAnswer);
}
