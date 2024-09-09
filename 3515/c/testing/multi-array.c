#include <stdio.h>

int main() {
    int table [3][4] = {{2, 3, 4, 5}};
    printf("%d\n", table[2][2]);

    int theNumber = 3;
    switch (theNumber) {
        case 25:
            printf("The number is 25\n");
            break;
        case 30:
            printf("The number is 30\n");
            break;
        default:
            printf("The number is not 25 or 30\n");
    }

    int speed;
    printf("Enter your speed:\n");
    scanf("%d", &speed);
    if (speed > 50) {
        printf("You are speeding\n");
    } else if (speed <= 50) {
        printf("You are not speeding\n");
    }
    else {
        printf("You are stopped\n");
    }


    int fuelAmount, fuelCapacity;
    printf("Enter the amount of fuel in the tank:\n");
    scanf("%d", &fuelAmount);
    printf("Enter the fuel capacity of the tank:\n");
    scanf("%d", &fuelCapacity);

    char *capacityTotal = (fuelAmount / fuelCapacity) < 0.1 ? "Red Light\n" : "Green Light\n";
    printf("%s\n", capacityTotal);

    return 0;
}