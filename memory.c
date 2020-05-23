#include <stdio.h>
#include <stdlib.h>

void arrayFill(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        array[i] = 42;
    }
}

void arrayPrint(int array[], int size) {
    int last = size - 1;

    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);
}

int main() {
    const int len = 10;
    int* array;
    int* bkp;

    array = (int*)malloc(len * sizeof(int));
    arrayFill(array, len);
    arrayPrint(array, len);

    bkp = array;
    array = (int*)realloc(array, (len + len) * sizeof(int));
    
    if ( array == NULL ) {
        printf("WARNING!\n");
        array = bkp;
    }

    arrayPrint(array, len * 2);

    free(array);

    return 0;
}
