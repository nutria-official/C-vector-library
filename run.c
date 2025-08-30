#include "vector.h"

void main() {
    vector *positions = vectorInit(sizeof(int));

    int val1 = 10;
    int val2 = 20;
    int val3 = 30;

    push(positions, &val1);
    push(positions, &val2);
    push(positions, &val3);

    int *ptr1 = read(positions, 0);
    int *ptr2 = read(positions, 1);
    int *ptr3 = read(positions, 2);

    printf("%d\n%d\n%d\n", *ptr1, *ptr2, *ptr3);

    pop(positions);

    int *test5 = read(positions, 2);

    printf("\n\n%d\n\n", *test5);

    push(positions, &val3);

    
    int *test1 = read(positions, 0);
    int *test2 = read(positions, 1);
    int *test3 = read(positions, 2);

    printf("%d\n%d\n", *test1, *test2);
    printf("%d\n", *test3);
}