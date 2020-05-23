#include <stdio.h>

void merge(int array[], int lo, int mid, int hi) {
    const int size = hi - lo;
    int buffer[size];
    int i = lo;
    int j = mid;
    int k = 0;

    for ( ; i < mid && j < hi; k++ ) {
        if ( array[i] < array[j] ) {
            buffer[k] = array[i];
            i += 1;
        } else {
            buffer[k] = array[j];
            j += 1;
        }
    }

    for ( ; i < mid; i++, k++ ) {
        buffer[k] = array[i];
    }
    for ( ; j < hi; j++, k++ ) {
        buffer[k] = array[j];
    }

    for ( i = 0, j = lo; i < size; i++, j++ ) {
        array[j] = buffer[i];
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
    int array[11] = {3,6,9,12,4,5,11,14,15,16,20};

    arrayPrint(array, 11);
    merge(array, 0, 4, 11);
    arrayPrint(array, 11);
    // 1 2 3 4 5 6 7 8 9 10


    return 0;
}