/*
* COP 3515 – Fall Semester 2024
*
* Homework #1: Password Strength Meter
*
* (Aiden Peyton)
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(void) {

    int maxLength;
    int minLength;
    bool allowPhrase;
    int minPhraseLength;
    bool allowOptional;
    int minOptionalTests;

    FILE *passwords1 = fopen("Proposed passwords #1.txt", "r");
    FILE *passwords2 = fopen("Proposed passwords #2.txt", "r");
    FILE *passwords3 = fopen("Proposed passwords #3.txt", "r");

    char password[100];
    while (fgets(password, 100, passwords1)) {
        printf("%s", password);
        printf("Test\n");
    }

    return 0;
}