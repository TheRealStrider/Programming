#include <stdio.h>

enum flavors {vanilla, chocolate, mint, strawberry}; // Enumeration for flavors of ice cream

int main() {

    float cornerOneSales[4]; // Array for corner1 sales
    float cornerTwoSales[4]; // Array for corner2 sales

    // Char arrays for ice cream types
    char vanillaType [9];
    char chocolateType [11];
    char mintType [6];
    char strawberryType [12];

    //Inputting ice cream flavors
    printf("Enter ice cream flavor #1:\n");
    fgets(vanillaType, sizeof(vanillaType), stdin);

    printf("Enter ice cream flavor #2:\n");
    fgets(chocolateType, sizeof(chocolateType), stdin);

    printf("Enter ice cream flavor #3:\n");
    fgets(mintType, sizeof(mintType), stdin);

    printf("Enter ice cream flavor #4:\n");
    fgets(strawberryType, sizeof(strawberryType), stdin);


    // Inputting sales of each corner
    // Corner 1
    printf("\nEnter corner 1 sales of vanilla\n"); // Wonder if you wanted to use value of previous variable?
    scanf("%f", &cornerOneSales[vanilla]);

    printf("Enter corner 1 sales of chocolate\n");
    scanf("%f", &cornerOneSales[chocolate]);

    printf("Enter corner 1 sales of mint\n");
    scanf("%f", &cornerOneSales[mint]);

    printf("Enter corner 1 sales of strawberry\n");
    scanf("%f", &cornerOneSales[strawberry]);

    // Corner 2
    printf("\nEnter corner 2 sales of vanilla\n");
    scanf("%f", &cornerTwoSales[vanilla]);

    printf("Enter corner 2 sales of chocolate\n");
    scanf("%f", &cornerTwoSales[chocolate]);

    printf("Enter corner 2 sales of mint\n");
    scanf("%f", &cornerTwoSales[mint]);

    printf("Enter corner 2 sales of strawberry\n");
    scanf("%f", &cornerTwoSales[strawberry]);

    // Total variables for ice cream flavor sales
    float totalVanillaSales = cornerOneSales[vanilla] + cornerTwoSales[vanilla];
    float totalChocolateSales = cornerOneSales[chocolate] + cornerTwoSales[chocolate];
    float totalMintSales = cornerOneSales[mint] + cornerTwoSales[mint];
    float totalStrawberrySales = cornerOneSales[strawberry] + cornerTwoSales[strawberry];

    // Total sales made for Bob :)
    float totalSales = totalVanillaSales + totalChocolateSales + totalMintSales + totalStrawberrySales;

    // Printing the total values
    printf("\nTotal vanilla sales: %.2f\n", totalVanillaSales);
    printf("Total chocolate sales: %.2f\n", totalChocolateSales);
    printf("Total mint sales: %.2f\n", totalMintSales);
    printf("Total strawberry sales: %.2f\n", totalStrawberrySales);
    printf("\nBob's Ice Cream total sales: %.2f", totalSales);

    return 0;
}
