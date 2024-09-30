#include <stdio.h>

int sumArray(int *array, int size);

int main(void) {
    // The ORIGINAL Array
    int theArray[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    theArray[0] = sumArray(theArray, 10);
    printf("Original array contents:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", theArray[i]);
    }
    printf("\n");
    // Updating original array without that jerk Peter knowing >:D
    int *updateArray = theArray;
    updateArray[3] = 101;
    updateArray[6] = 63;
    updateArray[9] = 21;
    *updateArray = sumArray(updateArray, 10);
    printf("Updated array contents:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", updateArray[i]);
    }
    printf("\n");

    return 0;
}

int sumArray(int *array, int size) {
    int sum = 0;
    for (int i = 1; i < size; i++) {
        sum += array[i];
    }
    return sum;
}
