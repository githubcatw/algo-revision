typedef struct {
    int start;
    int end;
    int capacity;
    int* data;
} Queue;

Queue* create_queue(int* data, int size);
int dequeue(Queue* queue);
void enqueue(Queue* queue, int value);
int queue_full(Queue* queue);
int queue_empty(Queue* queue);
