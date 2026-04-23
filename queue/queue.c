#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue* create_queue(int* data, int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue) {
        queue->data = data;
        queue->capacity = capacity;
        queue->end = 0;
        queue->start = 0;
    }
    return queue;
}

int queue_full(Queue* queue) {
    return queue->end == queue->capacity;
}

int queue_empty(Queue* queue) {
    return queue->end == queue->start;
}

void enqueue(Queue* queue, int value) {
    if (queue_full(queue)) {
        printf("E: queue at capacity\n");
        return;
    }

    // increment the end index and add the data
    queue->data[queue->end] = value;
    queue->end++;
}

int dequeue(Queue* queue) {
    if (queue_empty(queue)) {
        printf("E: queue empty\n");
    }
    // save the item at index start (we will need it later)
    int data = queue->data[queue->start];
    // increment the start index, then return the saved data
    queue->start++;
    return data;
}
