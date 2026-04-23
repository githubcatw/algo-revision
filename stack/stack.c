#include "stack.h"
#include<stdlib.h>
#include<stdio.h>

Stack* create_stack(int data[], int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack) {
        stack->data = data;
        stack->capacity = capacity;
        stack->end = STACK_EMPTY_INDEX;
    }
    return stack;
}

void stack_push(Stack* stack, int value) {
    // detect stack overflow
    if (stack->end == stack->capacity - 1) {
        printf("E: stack overflow detected\n");
        return;
    }

    // increase the end index
    stack->end++;
    // insert the value at the new end index
    stack->data[stack->end] = value;
}

int stack_pop(Stack* stack) {
    // detect stack underflow
    if (stack->end == -1) {
        printf("E: stack underflow detected\n");
        return -1;
    }
    // keep the last element
    int el = stack->data[stack->end];
    // decrease the end index
    stack->end--;
    // return the saved element
    return el;
}

int stack_empty(Stack *stack) {
    return stack->end == STACK_EMPTY_INDEX;
}
