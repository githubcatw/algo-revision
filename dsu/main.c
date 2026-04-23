#include "dsu.h"
#include <stdio.h>

void print_array(int* data, int size) {
    // pad to two characters
    for (int i = 0; i < size; i++) {
        printf("%2d ", data[i]);
    }
    printf("\n");
}

int main() {
    int fib[] = {2, 3, 5, 8, 13, 21, 34};
    DisjointSets* sets = create_sets(fib, 7);
    // merge a few numbers together
    union_sets(sets, 0, 1);
    union_sets(sets, 2, 5);
    union_sets(sets, 1, 4);
    union_sets(sets, 2, 3);

    // print the indices
    printf("      ");
    for (int i = 0; i < 7; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    // print the underlying data
    printf("data: ");
    print_array(sets->data, 7);
    printf("rank: ");
    print_array(sets->ranks, 7);
    printf("reps: ");
    print_array(sets->reps, 7);
    return 0;
}
