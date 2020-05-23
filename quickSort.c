#include <stdio.h>

int partition(int array[], int lo, int hi) {
    int mid = (lo + hi) / 2;
    int pivot = array[mid];
    int tail = lo;

    array[mid] = array[hi];
    array[hi] = pivot;

    for ( ; array[tail] < array[hi]; tail++ );
    for ( int i = tail + 1; i < hi; i++ ) {
        if ( array[i] < array[hi] ) {
            pivot = array[tail];
            
            array[tail] = array[i];
            array[i] = pivot;
            tail += 1;
        }
    }

    pivot = array[hi];
    array[hi] = array[tail];
    array[tail] = pivot;
    
    return tail;
}

void quickSort(int array[], int lo, int hi) {
    int pivot;

    if ( lo < hi ) {
        pivot = partition(array, lo, hi);
        quickSort(array, lo, pivot-1);
        quickSort(array, pivot+1, hi);
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
    int array[10] = {19,15,110,13,14,12,11,16,18,17};
    
    arrayPrint(array, 10);
    quickSort(array, 0, 9);
    arrayPrint(array, 10);
    
    return 0;
}
