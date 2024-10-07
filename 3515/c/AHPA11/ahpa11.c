#include <stdio.h>
// Created by me duh (Aiden Peyton)
void switcher (int *array, int length); // I will never stop doing this

int main(void) {
    int finalExams[15] = {90, 82, 65, 79, 67, 82, 94, 64, 88, 78, 92,
                          61, 96, 83, 74}; // The intact array | I'm gonna change it >:)
    int lengthOfArray = sizeof(finalExams) / sizeof(finalExams[0]); // Length of array | This is kinda obvious
    printf("Scores before changing:\n");
    for (int i = 0; i < lengthOfArray; i++) { // Printing the array | He has no idea what I'm about to do
        printf("%d ", finalExams[i]);
    }
    switcher(finalExams, lengthOfArray); // Good old switcher
    printf("\n\nScores after changing:\n");
    for (int i = 0; i < lengthOfArray; i++) { // Yeah, I'm gonna print it again
        printf("%d ", finalExams[i]);
    }
}

void switcher (int *array, int length) { // The switcher function | Nothing special
    for (int i = 0; i < length; i++) {
        if (array[i] < 70) {
            array[i] += 10;
        }
    }
} // My humor is beyond your understanding