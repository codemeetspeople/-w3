#include <stdio.h>

int main() {
    int array[16] = {0,1,0,3,0,1,0,3,3,3,3,0,1,1,0,1};
    int count[4] = {0,0,0,0};

    for ( int i = 0; i < 16; i++ ) {
        int index = array[i];
        count[index] += 1;
    }

    for ( int i = 0; i < 4; i++ ) {
        printf("%d: %d\n", i, count[i]);
    }
    
    return 0;
}
