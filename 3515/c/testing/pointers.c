#include <stdio.h>

int main(void) {
    int i = 10;
    int *p = &i;

    printf("Value of i: %d\nValue of p: %p\nValue of *p: %d\n", i, p, *p);
    *p += 23;
    printf("Value of i: %d\nValue of p: %p\nValue of *p: %d\n", i, p, *p);
}