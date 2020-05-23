#include <stdio.h>

enum MONTHS {
    JAN = 1,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
};

int getDays(int month) {
    switch ( month ) {
        case JAN:
            return 31;
        case FEB:
            return 28;
        case MAR:
            return 31;
        case APR:
            return 30;
        case MAY:
            return 31;
        case JUN:
            return 30;
        case JUL:
            return 30;
        case AUG:
            return 31;
        case SEP:
            return 31;
        case OCT:
            return 30;
        case NOV:
            return 31;
        case DEC:
            return 31;
        default:
            return -1;
    }
}

int main() {
    printf("jan: %d\n", getDays(JAN));
    printf("feb: %d\n", getDays(2));
    printf("unknown month: %d\n", getDays(15));
    return 0;
}
