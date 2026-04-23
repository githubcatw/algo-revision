#define STACK_EMPTY_INDEX -1

typedef struct Stack {
    int end;
    int capacity;
    int* data;
} Stack;

int stack_pop(Stack* stack);
void stack_push(Stack* stack, int value);
int stack_empty(Stack* stack);
Stack* create_stack(int data[], int capacity);
