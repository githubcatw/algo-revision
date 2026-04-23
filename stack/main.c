#include "stack.h"
#include<stdio.h>

int main() {
    int stack_back[10];
    Stack* stack = create_stack(stack_back, 10);

    // push some data
    stack_push(stack, 2);
    stack_push(stack, 3);
    stack_push(stack, 5);
    stack_push(stack, 8);
    stack_push(stack, 13);

    // pop everything from the stack
    while (!stack_empty(stack)) {
        printf("%d ", stack_pop(stack));
    }
}
