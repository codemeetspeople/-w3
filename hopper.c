#include <stdio.h>

#define LEN 100

int main() {
    int maxJump, cell;
    unsigned long long ways[LEN];

    scanf("%d %d", &maxJump, &cell);

    for ( int i = 0; i < maxJump; i++ ) {
        ways[i] = (unsigned long long)1 << i;
    }

    for ( int i = maxJump; i < cell; i++ ) {
        unsigned long long way = 0;

        for ( int j = i - maxJump; j < i; j++ ) {
            way += ways[j];
        }
        ways[i] = way;
    }

    printf("%llu\n", ways[cell-1]);

    return 0;
}
