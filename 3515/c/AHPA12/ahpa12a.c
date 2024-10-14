#include <stdio.h>

int main(void) {
    int finalExams[10] = {0};
    int *startPtr = &finalExams[0];
    int *endPtr = &finalExams[4];
    int *testPtr;

    for (int i = 0; i < sizeof finalExams / sizeof finalExams[0]; i++) { // Printing array before changing
        printf("%d ", finalExams[i]);
    }
    printf("\n");

    // Changing the array using pointers
    *startPtr = 90;
    *(startPtr + 1) = 82;
    *(startPtr + 2) = 65;
    *(startPtr + 3) = 79;
    *endPtr = 67;

    // Adding new students to the array
    *(endPtr + 1) = 81;
    *(endPtr + 2) = 72;

    for (int i = 0; i < sizeof finalExams / sizeof finalExams[0]; i++) { // Printing array after changing
        printf("%d ", finalExams[i]);
    }
    printf("\n");

}