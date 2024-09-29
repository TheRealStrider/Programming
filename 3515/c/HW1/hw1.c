/*
* COP 3515 – Fall Semester 2024
*
* Homework #1: Password Strength Meter
*
* (Aiden Peyton)
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Some odd reason this isn't being used :/
#include <string.h>

FILE *chooseFile(int fileNumber); // Function declaration

int main(void) {

    FILE *file;
    int maxLength;
    int minLength;
    bool allowPhrase;
    int minPhraseLength;
    bool allowOptional;
    int minOptionalTests;

    char lines[100];

    // THE ALGORITHM >:D
    for (int i = 0; i < 3; i++) {
        file = chooseFile(i);
        char fileContents[20][100]; // Stores file contents
        int lineNumber = 0;

        // Reading files and putting contents in array
        while (fgets(lines, sizeof(lines), file)) {
            strcpy(fileContents[lineNumber], lines);
            lineNumber++; // Increments line number to see where each file ends
        }
        fclose(file);
        strcpy(fileContents[lineNumber], "STOP"); // Adding STOP to check where each file ends as array is bigger than file

        printf("Processing password file #%d\n\n", i + 1); // Shows what password file is selected

        //Password settings - There has to be a better way.... ._.
        for (int j = 0; j < 6; j++) {
            if (j == 0) {maxLength = strtol(fileContents[j], nullptr, 10);}
            if (j == 1) {minLength = strtol(fileContents[j], nullptr, 10);}
            if (j == 2) { // To the Future!
                allowPhrase = strtol(fileContents[j], nullptr, 10) == 1;
                if (allowPhrase) {
                    minPhraseLength = strtol(fileContents[j + 1], nullptr, 10);
                    allowOptional = strtol(fileContents[j + 2], nullptr, 10) == 1;
                    minOptionalTests = (allowOptional) ? strtol(fileContents[j + 3], nullptr, 10) : 0;
                }
                else {
                    minPhraseLength = 0;
                    allowOptional = strtol(fileContents[j + 1], nullptr, 10);
                    minOptionalTests = (allowOptional) ? strtol(fileContents[j + 2], nullptr, 10) : 0;
                }
            }
        }

        //Print the password specifications
        printf("Maximum password length: %d\n", maxLength);
        printf("Minimum password length: %d\n", minLength);
        if (allowPhrase) {
            printf("Pass phrases are allowed\nPass phrase minimum length: %d\n", minPhraseLength);
        }
        else {
            printf("Pass phrases are NOT allowed\n");
        }
        if (allowOptional) {
            printf("Optional Tests are allowed\nMinimum Optional Tests to be used: %d\n\n", minOptionalTests);
        }
        else {
            printf("Optional Tests are NOT allowed\n\n");
        }

        // Password validator - EVERYTHING IS IN A FOR LOOP WTF
        for (int j = 0; j < 20; j++) {
            bool overMin;
            bool underMax;
            bool doesRepeat;
            bool containsLNS; // Letters, Numbers, Special

            if (strcmp(fileContents[j], "STOP") == 0) { // Checks if file is over
                break;
            }
            else {
                if (strtol(fileContents[j], nullptr, 10) == 0 && fileContents[j][0] != '0') {
                    int passLen = (int) strlen(fileContents[j]) -1;
                    if ((int) passLen < 1) {continue;}
                    // START SOLVING FOR PASSWORDS -- THIS IS WHERE IT ONLY SHOWS PASSWORDS
                    printf("Potential password: %s", fileContents[j]);
                    bool isPhrase = false;
                    bool failedPass = false;
                    for (int k = 0; k < passLen; k++) { // Checking if password is a phrase
                        if (fileContents[j][k] == ' ') {
                            isPhrase = true;
                            break;
                        }
                    }
                    if (isPhrase && !allowPhrase) { // Literally never used :(
                        printf("Pass phrases are NOT allowed\n");
                        printf("Password failed - it cannot be used.\n");
                        continue;
                    }

                    // --REQUIRED TESTS--
                    printf("\n\t\t:REQUIRED TESTS:\n");
                    printf("\t[1] Minimum Length: ");
                    if (passLen < minLength) { //Minimum Length
                        printf("FAILED\n\t\tThe password must be at least %d characters long.\n", minLength);
                        failedPass = true;
                    }
                    else {printf("PASSED\n");}
                    printf("\t[2] Maximum Length: ");
                    if (!isPhrase && passLen > maxLength) { // Maximum Length
                        printf("FAILED\n\t\tThe password must be fewer than %d characters.\n", maxLength);
                        failedPass = true;
                    }
                    else {printf("PASSED\n");}

                    bool repeatedSeq = false;
                    for (int k = 0; k < passLen -2; k++) { // Repeated Sequence of Characters Logic -> RSC
                        if (fileContents[j][k] == fileContents[j][k + 1] && fileContents[j][k] == fileContents[j][k + 2]) {
                            repeatedSeq = true;
                            break;
                        }
                    }
                    printf("\t[3] NO Repeats: ");
                    if (repeatedSeq) { // RSC
                        printf("FAILED\n\t\tThe password may not contain sequence of three or more repeated characters.\n");
                        failedPass = true;
                    }
                    else {printf("PASSED\n");}

                    bool containsUpper = false;
                    bool containsLower = false;
                    int numDigits = 0;
                    int numSpecial = 0;
                    for (int k = 0; k < passLen; k++) { // Contains Letters Numbers AND Special -> LNS
                        char currentChar = fileContents[j][k];
                        if (currentChar >= 'A' && currentChar <= 'Z') {containsUpper = true;}
                        else if (currentChar >= 'a' && currentChar <= 'z') {containsLower = true;}
                        else if (currentChar >= '0' && currentChar <= '9') {numDigits++;}
                        else if ((currentChar >= ' ' && currentChar <= '/') || (currentChar >= ':' && currentChar <= '@')
                            || (currentChar >= '[' && currentChar <= '`') || (currentChar >= '{' && currentChar <= '~')) {
                                numSpecial++;
                        }
                    }
                    printf("\t[4] Contains letters, numbers, AND symbols: ");
                    if (!((containsUpper || containsLower) && (numDigits > 0) && (numSpecial > 0))) { // LNS
                        printf("FAILED\n\t\tThe password must contain letters, numbers, AND symbols.\n");
                        failedPass = true;
                    }
                    else {printf("PASSED\n");}

                    // --OPTIONAL TESTS--
                    int passedOptional = 0;
                    if (allowOptional) {
                        printf("\n\t\t:OPTIONAL TESTS:\n");
                        if (!isPhrase || passLen < minPhraseLength) {
                            printf("\t[5] Contains lowercase letter: ");
                            if (!containsLower) { // Contains lower
                                printf("FAILED\n\t\tThe password must contain at least one lowercase letter.\n");
                            }
                            else {
                                printf("PASSED\n");
                                passedOptional++;
                            }

                            printf("\t[6] Contains uppercase letter: ");
                            if (!containsUpper) { // Contains upper
                                printf("FAILED\n\t\tThe password must contain at least one uppercase letter.\n");
                            }
                            else {
                                printf("PASSED\n");
                                passedOptional++;
                            }

                            printf("\t[7] Contains at least 2 digits: ");
                            if (numDigits < 2) { // Contains 2 <= digits
                                printf("FAILED\n\t\tThe password must contain at least two numbers.\n");
                            }
                            else {
                                printf("PASSED\n");
                                passedOptional++;
                            }

                            printf("\t[8] Contains at least 2 special characters: ");
                            if (numSpecial < 2) { // Contains 2 <= special characters
                                printf("FAILED\n\t\tThe password must contain at least two special characters.\n");
                            }
                            else {
                                printf("PASSED\n");
                                passedOptional++;
                            }
                            printf("\tTotal Number of Optional Tests Passed: %d\n", passedOptional);
                        }
                        else {printf("\tPhrase does NOT need to do Optional Tests\n");}
                    }

                    //Pass or Not
                    printf("\n\tRequired Tests: %s\n", (failedPass) ? "FAILED": "PASSED");
                    if (allowOptional) {
                        if (!isPhrase || passLen < minPhraseLength) { // Is NOT a phrase >:(
                            printf("\tOptional Tests: %s\n", (passedOptional >= minOptionalTests) ? "PASSED" : "FAILED");
                            if (passedOptional >= minOptionalTests && !failedPass) {
                                printf("\tPassword CAN be used.\n");
                            }
                            else { // Is phrase :D
                                printf("\tPassword CANNOT be used.\n");
                            }
                        }
                        else {printf("\t%s.\n", (failedPass) ? "Password CANNOT be used" : "Password CAN be used");}
                    }
                    printf("\n");
                }
            }
        }
    }
    return 0;
}

FILE *chooseFile (int fileNumber) {
    FILE *passwords1 = fopen("Proposed passwords #1.txt", "r");
    FILE *passwords2 = fopen("Proposed passwords #2.txt", "r");
    FILE *passwords3 = fopen("Proposed passwords #3.txt", "r");
    FILE *x = nullptr;

    switch (fileNumber) { // Choose the file
        case 0:
            x = passwords1;
            break;
        case 1:
            x = passwords2;
            break;
        case 2:
            x = passwords3;
            break;
        default:
            break;
    }
    return x;
}
