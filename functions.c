#include <stdio.h>

typedef int (*function)(int, int);

int mult(int x, int y) {
    return x * y;
}

int sum(int x, int y) {
    return x + y;
}

typedef struct {
    function sum;
    function mult;
} math;


int reduce(function handler, int array[], int size) {
    int result = array[0];

    for ( int i = 1; i < size; i++ ) {
        result = handler(result, array[i]);
    }
    return result;
}

void arrayPrint(int array[], int size) {
    int last = size - 1;

    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);
}

void arrayFill(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        array[i] = i + 1;
    }
}

int main() { 
    const int len = 10;
    int array[len];
    function list[2] = {sum, mult};
    math m = {sum, mult};

    // arrayFill(array, len);
    // arrayPrint(array, len);

    // int arraySum = reduce(sum, array, len);
    // int factorial = reduce(mult, array, len);

    // printf("sum: %d\n", arraySum);
    // printf("factorial: %d\n", factorial);

    // printf("%d\n", list[0](5, 10));
    // printf("%d\n", list[1](5, 10));

    printf("%d\n", m.sum(5, 10));
    printf("%d\n", m.mult(5, 10));

    return 0;
}
