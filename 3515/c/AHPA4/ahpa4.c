#include <stdio.h>

int main() {

    int bankAccounts[2][2] = {{500, 1000}, {750, 325}}; // [0][0] = a, checking [1][1] = b, savings
    char userName[3];
    char accountType[3];
    int amountWithdraw;
    int indexFirst = 0; // Helps remove redundant code
    int indexSecond = 0; // Helps remove redundant code

    printf("Enter your name:\n");
    fgets(userName, 3, stdin);

    printf("Would you like to withdraw from (c)hecking or (s)avings?\n");
    fgets(accountType, 3, stdin);

    printf("How much would you like to withdraw?\n");
    scanf("%d", &amountWithdraw); // NOLINT(*-err34-c)
    switch (userName[0]) { // Choosing which name to use for array
        case 'a':
            indexFirst = 0;
            break;
        case 'b':
            indexFirst = 1;
            break;
        default:
            printf("Incorrect name chosen\n");
            break;
    }

    switch (accountType[0]) { // Choosing which account to use for array
        case 'c':
            indexSecond = 0;
            break;
        case 's':
            indexSecond = 1;
            break;
        default:
            printf("Incorrect account chosen\n");
    }

    // ATM Algorithm
    if (bankAccounts[indexFirst][indexSecond] < amountWithdraw) {
        printf("Amount is greater than balance remaining\n");
    }
    else {
        printf("Amount in account to be withdrawn from: $%d\n", bankAccounts[indexFirst][indexSecond]);
        if (amountWithdraw >= 100) {
            printf("$100 bill\n");
            bankAccounts[indexFirst][indexSecond] -= 100;
            amountWithdraw -= 100;
        }
        if (amountWithdraw >= 100) {
            printf("$100 bill\n");
            bankAccounts[indexFirst][indexSecond] -= 100;
            amountWithdraw -= 100;
        }
        if (amountWithdraw >= 50) {
            printf("$ 50 bill\n");
            bankAccounts[indexFirst][indexSecond] -= 50;
            amountWithdraw -= 50;
        }
        if (amountWithdraw >= 20) {
            printf("$ 20 bill\n");
            bankAccounts[indexFirst][indexSecond] -= 20;
            amountWithdraw -= 20;
        }
        if (amountWithdraw >= 20) {
            printf("$ 20 bill\n");
            bankAccounts[indexFirst][indexSecond] -= 20;
            amountWithdraw -= 20;
        }
        if (amountWithdraw >= 20) {
            printf("$ 20 bill\n");
            bankAccounts[indexFirst][indexSecond] -= 20;
            amountWithdraw -= 20;
        }
        if (amountWithdraw >= 20) {
            printf("$ 20 bill\n");
            bankAccounts[indexFirst][indexSecond] -= 20;
            amountWithdraw -= 20;
        }
        if (amountWithdraw >= 10) {
            printf("$ 10 bill\n");
            bankAccounts[indexFirst][indexSecond] -= 10;
            amountWithdraw -= 10;
        }
        if (amountWithdraw >= 5) {
            printf("$  5 bill\n");
            bankAccounts[indexFirst][indexSecond] -= 5;
            amountWithdraw -= 5;
        }
        if (amountWithdraw >= 1) {
            printf("$  1 bill\n");
            bankAccounts[indexFirst][indexSecond] -= 1;
            amountWithdraw -= 1;
        }
        if (amountWithdraw >= 1) {
            printf("$  1 bill\n");
            bankAccounts[indexFirst][indexSecond] -= 1;
            amountWithdraw -= 1;
        }
        if (amountWithdraw >= 1) {
            printf("$  1 bill\n");
            bankAccounts[indexFirst][indexSecond] -= 1;
            amountWithdraw -= 1;
        }
        if (amountWithdraw >= 1) {
            printf("$  1 bill\n");
            bankAccounts[indexFirst][indexSecond] -= 1;
            amountWithdraw -= 1;
        }
        printf("Amount in account after withdraw: $%d", bankAccounts[indexFirst][indexSecond]);
    }
}
