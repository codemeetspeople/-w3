#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int capacity;
    int current;
    int* array;
} list;

void push_back(list* lst, int value) {
    if ( lst->current == lst->capacity ) {
        int newCapacity = lst->capacity + 10;
        int* newArray = (int*)realloc(
            lst->array, newCapacity * sizeof(int)
        );
        if ( newArray == NULL ) {
            printf("Can not allocate memory\n");
            return;
        }
        lst->capacity = newCapacity;
        lst->array = newArray;
    }
    lst->array[lst->current] = value;
    lst->current += 1;
}

int pop_back(list* lst) {
    if ( lst->current == 0 ) {
        printf("pop_back: Empty list\n");
        return (int)NULL;
    }
    lst->current -= 1;
    return lst->array[lst->current];
}

void print(list* lst) {
    if ( lst->current == 0 ) {
        printf("print: Empty list.\n");
        return;
    }
    int last = lst->current - 1;

    for ( int i = 0; i < last; i++ ) {
        printf("%d ", lst->array[i]);
    }
    printf("%d\n", lst->array[last]);
}

void release(list* lst) {
    lst->capacity = 0;
    lst->current = 0;
    free(lst->array);
}

int main() {
    list myList = {10, 0, (int*)malloc(10*sizeof(int))};

    print(&myList);
    for ( int i = 1; i <= 5; i++ ) {
        push_back(&myList, i);
    }
    print(&myList);
    for ( int i = 7; i <= 19; i++ ) {
        push_back(&myList, i);
    }
    print(&myList);
    
    pop_back(&myList);
    pop_back(&myList);
    pop_back(&myList);
    pop_back(&myList);
    
    print(&myList);

    release(&myList);

    return 0;
}
