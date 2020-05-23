#include <stdio.h>

typedef int (*function)(int, int);

int mult(int x, int y) {
    return x * y;
}

int sum(int x, int y) {
    return x + y;
}

int diff(int x, int y) {
    return x - y;
}

int notImplemented(int x, int y) {
    printf("Action not implemented\n");
    return (int)NULL;
}

enum ACTIONS {
    SUM,
    DIFF,
    MULT
};

function factory(int action) {
    switch ( action ) {
        case SUM:
            return sum;
        case DIFF:
            return diff;
        case MULT:
            return mult;
        default:
            return notImplemented;
    }
}


int main() {
    for ( ; ; ) {
        int action;
        int x, y;

        printf("Actions to perform:\n");
        printf("    %d: sum\n", SUM);
        printf("    %d: diff\n", DIFF);
        printf("    %d: mult\n", MULT);

        scanf("%d", &action);
        scanf("%d %d", &x, &y);

        printf("Result: %d\n", factory(action)(x, y));
        printf("\n*******\n\n");
    }

    return 0;
}
