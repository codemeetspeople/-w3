#include <stdio.h>

int main() {
    int arr1[5] = {1,2,3,4,5};
    int arr2[5] = {6,7,8,9,10};

    int i = 0, j = 0;

    for ( ; i < 5 && j < 5; ) {
        if ( arr1[i] < arr2[j] ) {
            printf("%d ", arr1[i]);
            i += 1;
        } else {
            printf("%d ", arr2[j]);
            j += 1;
        }
    }

    for ( ; i < 5; i++ ) {
        printf("%d ", arr1[i]);
    }
    for ( ; j < 5; j++ ) {
        printf("%d ", arr2[j]);
    }

    printf("\n");

    return 0;
}
