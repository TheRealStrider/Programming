/*
* COP 3515 – Fall Semester 2024
*
* Homework #2: Spotting The Hacker
*
* (Aiden Peyton)
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

void decimalToBinary (unsigned char value, char *binaryArray);
void printBlock(unsigned char block[8][10]);
void readInBlocks (char lines[100], int lineNumber, unsigned char parityData[8][10], int parityDataINT[8][10]);
void verticalHorizontalParityCheck (unsigned char parityData[8][10]);
unsigned char BinaryToDecimal (char binary[9]);

int main(void) {
    FILE *parity = fopen("White House Transmission Data - Parity.txt", "r");
    FILE *twoDParity = fopen("White House Transmission Data - 2D Parity.txt", "r");
    FILE *checkSum = fopen("White House Transmission Data - Checksum.txt", "r");

    for (int i = 0; i < 3; i++) {
        char lines[100];
        if (i == 0) { // Parity Checking
            printf("**Part 1 - Parity Check Processing\n\n\n");
            int lineNumber = 1; // Keep track of what line we are on

            while (fgets(lines, 100, parity) != NULL) {
                int nonParity[8];
                char binary[8][9], binaryNumbers[9];
                int parityBit;
                sscanf(lines, "%d %d %d %d %d %d %d %d %d", &nonParity[0], &nonParity[1], &nonParity[2], &nonParity[3],
                       &nonParity[4], &nonParity[5], &nonParity[6], &nonParity[7], &parityBit);

                // Convert decimal to binary and storing in array
                for (int j = 0; j < 8; j++) {
                    decimalToBinary(nonParity[j], binaryNumbers);
                    strcpy(binary[j], binaryNumbers);
                }

                printf("Transmission line number: %d\n\nData stream:\n", lineNumber);
                lineNumber++;
                for (int j = 0; j < 8; j++) { // Printing out the data stream
                    printf("%d ", nonParity[j]);
                }
                printf("\nParity byte: %d\n\n", parityBit);

                /*
                 * Calculating what item we are on currently | A
                 * Calculating how many 1s are in the binary number | B
                 * Checking whether the parity matches | C
                 */

                for (int j = 0; j < 8; j++) {
                    printf("data item = %d, binary = %s\n", nonParity[j], binary[j]); // A

                    int fixedParity = parityBit % 2; // Start of B
                    int nonParityCopy = nonParity[j];
                    int numOnes = 0;
                    while (nonParityCopy > 0) {
                        if (nonParityCopy & 1) {
                            numOnes++;
                        }
                        nonParityCopy >>= 1;
                    } // End of B

                    if (numOnes % 2 == fixedParity) { // Start of C
                        printf("No error in transmission byte %d\n\n", j + 1);
                    }
                    else {
                        printf("Error in transmission byte %d\n\n", j + 1);
                    } // End of C
                }
            }
            printf("\n\n");
        }
        else if (i == 1) {
            printf("**Part 2 - Checksum Processing\n\n\n");

            while (fgets(lines, 100, checkSum) != NULL) {
                int parityDataINT[8];
                int checkSumINT;
                unsigned char parityData[8];
                char binary[8][9], binaryNumbers[9];
                unsigned char checkSumByte, binaryCopy;
                sscanf(lines, " %d %d %d %d %d %d %d %d %d", &parityDataINT[0], &parityDataINT[1], &parityDataINT[2], &parityDataINT[3], &parityDataINT[4], &parityDataINT[5],
                       &parityDataINT[6], &parityDataINT[7], &checkSumINT);

                for (int j = 0; j < 8; j++) {
                    parityData[j] = (unsigned char) parityDataINT[j];
                }
                checkSumByte = (unsigned char) checkSumINT;

                printf("Data stream:\n");
                for (int j = 0; j < 8; j++) {
                    printf("%u ", parityData[j]);
                }
                printf("\nChecksum byte: %u\n\n", checkSumByte);

                for (int j = 0; j < 8; j++) {
                    decimalToBinary(parityData[j], binaryNumbers);
                    strcpy(binary[j], binaryNumbers);
                }

                for (int j = 0; j < 8; j++) {
                    printf("parityData[i] = %u, binary = %s\n\n", parityData[j], binary[j]);
                }

                // Calculating the sum of the data items
                printf("\nSum of data items = ");
                unsigned int sum = 0;
                for (int j = 0; j < 8; j++) {
                    sum += parityData[j];
                }
                char sumBinary[9];
                decimalToBinary(sum, sumBinary);
                printf("%d, binary = %s\n\n", sum, sumBinary);

                // Checksum and binary of checksum
                char checkSumBinary[9];
                decimalToBinary(checkSumByte, checkSumBinary);
                printf("Checksum value = %d, binary = %s\n\n", checkSumByte, checkSumBinary);

                // Calculating the sum of the data items and checksum
                unsigned char sumCheckSum = sum + checkSumByte;
                char sumCheckSumBinary[9];
                decimalToBinary(sumCheckSum, sumCheckSumBinary);
                printf("Sum after adding checksum = %d, binary = %s\n", sumCheckSum, sumCheckSumBinary);

                // Calculating the complement of the sum
                unsigned char complement = ~sumCheckSum;
                char complementBinary[9];
                decimalToBinary(complement, complementBinary);
                printf("Sum after complement = %u, binary = %s\n\n", complement, complementBinary);

                if (complement == 0) {
                    printf("Checksum: No errors in transmission\n\n");
                }
                else {
                    printf("Checksum: Errors in transmission\n\n");
                }

            }
        }
        else {
            printf("**Part 3 - Two-dimensional Parity Check Processing\n\n\n");
            int lineNumber = 1, blockNumber = 1;
            int parityDataINT1[8][10], parityDataINT2[8][10], parityDataINT3[8][10], parityDataINT4[8][10], parityDataINT5[8][10];
            unsigned char parityData1[8][10], parityData2[8][10], parityData3[8][10], parityData4[8][10], parityData5[8][10];
            while (fgets(lines, 100, twoDParity) != NULL) {
                if (lineNumber == 9) {
                    lineNumber = 1;
                    blockNumber++;
                    continue;
                }

                if (blockNumber == 1) {
                    readInBlocks(lines, lineNumber, parityData1, parityDataINT1);
                }
                else if (blockNumber == 2) {
                    readInBlocks(lines, lineNumber, parityData2, parityDataINT2);
                }
                else if (blockNumber == 3) {
                    readInBlocks(lines, lineNumber, parityData3, parityDataINT3);
                }
                else if (blockNumber == 4) {
                    readInBlocks(lines, lineNumber, parityData4, parityDataINT4);
                }
                else {
                    readInBlocks(lines, lineNumber, parityData5, parityDataINT5);
                }

                lineNumber++;
            }


            for (int j = 0; j < 5; j++) {
                printf("==> Processing Transmission Block %d\n\nData streams:\n", j + 1);
                if (j == 0) {
                    printBlock(parityData1);
                    printf("\n\n");
                    verticalHorizontalParityCheck(parityData1);
                }
                else if (j == 1) {
                    printBlock(parityData2);
                    printf("\n\n");
                    verticalHorizontalParityCheck(parityData2);
                }
                else if (j == 2) {
                    printBlock(parityData3);
                    printf("\n\n");
                    verticalHorizontalParityCheck(parityData3);
                }
                else if (j == 3) {
                    printBlock(parityData4);
                    printf("\n\n");
                    verticalHorizontalParityCheck(parityData4);
                }
                else {
                    printBlock(parityData5);
                    printf("\n\n");
                    verticalHorizontalParityCheck(parityData5);
                }

            }

        }

    }
}

void decimalToBinary(unsigned char value, char *binaryArray) {
    // Loop through each bit position
    for (int i = 0; i < 8; i++) {
        // Check if the i-th bit is set
        binaryArray[7 - i] = (value & (1 << i)) ? '1' : '0';
    }
    // Null-terminate the string
    binaryArray[8] = '\0';
}

void printBlock(unsigned char block[8][10]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%u ", block[i][j]);
        }
        printf("[V: %u] [H: %u]\n", block[i][8], block[i][9]);
    }
}

void readInBlocks (char lines[100], int lineNumber, unsigned char parityData[8][10], int parityDataINT[8][10]) {
    sscanf(lines, "%d %d %d %d %d %d %d %d %d %d", &parityDataINT[lineNumber - 1][0],
           &parityDataINT[lineNumber - 1][1], &parityDataINT[lineNumber - 1][2],
           &parityDataINT[lineNumber - 1][3],
           &parityDataINT[lineNumber - 1][4], &parityDataINT[lineNumber - 1][5],
           &parityDataINT[lineNumber - 1][6], &parityDataINT[lineNumber - 1][7],
           &parityDataINT[lineNumber - 1][8], &parityDataINT[lineNumber - 1][9]);
    for (int j = 0; j < 10; j++) {
        parityData[lineNumber - 1][j] = (unsigned char) parityDataINT[lineNumber - 1][j];
    }
}

void verticalHorizontalParityCheck (unsigned char parityData[8][10]) {
    for (int k = 0; k < 8; k++) {
        // Vertical parity
        char verticalBinary[9];
        int verticalParityByte[8] = {0};
        unsigned char verticalCheckParityByte;
        int horizontalCheckParityByte = 0;

        printf("**Vertical processing transmission line %d\n", k);
        for (int vv = 0; vv < 8; vv++) {
            char binary[9];
            decimalToBinary(parityData[vv][k], binary);
            printf("val%d = %u, %s\n", vv + 1, parityData[vv][k], binary);
            for (int b = 0; b < 8; b++) {
                verticalParityByte[b] += (binary[b] == '1') ? 1 : 0;
            }
        }
        for (int b = 0; b < 8; b++) {
            verticalBinary[b] = (verticalParityByte[b] % 2 == 0) ? '0' : '1';
        }
        verticalBinary[8] = '\0';
        verticalCheckParityByte = BinaryToDecimal(verticalBinary);
        printf("\n\ncheckParityByte = %u, vertParityByte[%d] = %u\n", verticalCheckParityByte, k, parityData[k][8]);
        printf("Transmission line %d %s vertical parity\n\n\n", k, (verticalCheckParityByte == parityData[k][8]) ? "passed" : "failed");

        // Horizontal parity
        printf("**Horizontal processing transmission line %d\n", k);
        int position4 = 0, position6 = 0;
        for (int hh = 0; hh < 8; hh++) {
            char binary[9];
            decimalToBinary(parityData[k][hh], binary);
            printf("val%d = %u, %s\n", hh + 1, parityData[k][hh], binary);
            if (binary[5] == '1') {
                position4 += 4;
            }
            if (binary[3] == '1') {
                position6 += 16;
            }
        }

        printf("\n\nAdding bit position 4 to checksum: %d\n", position4);
        printf("Adding bit position 6 to checksum: %d\n\n", position6);
        horizontalCheckParityByte = (position4 + position6);
        printf("checkParityByte = %d, horizParityByte[%d] = %u\n", horizontalCheckParityByte, k, parityData[k][9]);
        printf("Transmission line %d %s horizontal parity\n\n\n", k, (horizontalCheckParityByte == parityData[k][9]) ? "passed" : "failed");

    }
}

unsigned char BinaryToDecimal (char binary[9]) {
    unsigned char decimal = 0;
    for (int i = 0; i < 8; i++) {
        decimal += (binary[i] == '1') ? (int)pow(2, 7 - i) : 0;
    }
    return decimal;
}

/*
 * FINISH PART 3
 * COMPLETE VERTICAL PARITY
 * COMPLETE HORIZONTAL PARITY
 *
 */
