#include "heap.h"
#include<stdio.h>

void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int fib[] = {3, 5, 2, 8, 21, 13};
    int result[6];
    heapsort(fib, 6, result);
    print_array(fib, 6);
    print_array(result, 6);
}
