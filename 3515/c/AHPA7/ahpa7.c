#include <stdio.h>

double tempToTemp (char typeTemp, double tempValue);

int main(void) {

    char typeTemp[3]; // Type of Temperature used (Fahrenheit or Celsius)
    int tempValue;

    // Getting user information
    printf("What type of temperature will you be entering (c/f)\n");
    fgets(typeTemp, sizeof(typeTemp), stdin);

    if (typeTemp[0] == 'F') { // Converting uppercase to lowercase
        typeTemp[0] = 'f';
    }
    else if (typeTemp[0] == 'C') {
        typeTemp[0] = 'c';
    }

    printf("What temperature value should be converted?\n");
    scanf("%d", &tempValue);

    double convertedTempValue = tempToTemp(typeTemp[0], (double) tempValue); // Storing function return

    // Output
    switch (typeTemp[0]) {
        case 'f':
            printf("Given a Fahrenheit temperature of %.2f,\n the equivalent Celsius temperature is %.2f",
                   (float) tempValue, convertedTempValue);
            break;
        case 'c':
            printf("Given a Celsius temperature of %.2f,\n the equivalent Fahrenheit temperature is %.2f",
                   (float) tempValue, convertedTempValue);
            break;
        default:
            break;
    }

    return 0;
}

double tempToTemp (char typeTemp, double tempValue) {
    switch (typeTemp) {
        case 'f':
            return (tempValue - 32.0) / 1.8;
        case 'c':
            return (tempValue * 1.8) + 32;
        default:
            return 0;
    }
}