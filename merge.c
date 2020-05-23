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

void mergeSort(int array[], int lo, int hi) {
    int middle = (lo + hi) / 2;

    if ( lo < middle ) {
        mergeSort(array, lo, middle);
        mergeSort(array, middle, hi);
        merge(array, lo, middle, hi);
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
    int array[10] = {9,5,10,1,2,4,3,6,8,7};

    arrayPrint(array, 10);
    mergeSort(array, 0, 10);
    arrayPrint(array, 10);

    return 0;
}
