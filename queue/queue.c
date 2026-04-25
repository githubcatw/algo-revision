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
    // check if the next iteration of enqueue would reach the start index
    return (queue->end + 1) % queue->capacity == queue->start;
}

int queue_empty(Queue* queue) {
    return queue->end == queue->start;
}

void enqueue(Queue* queue, int value) {
    if (queue_full(queue)) {
        printf("E: queue at capacity\n");
        return;
    }

    // add the data
    queue->data[queue->end] = value;
    // increment the end index, looping back to the start
    // if the index is more than the capacity (using modulo)
    queue->end = (queue->end + 1) % queue->capacity;
}

int dequeue(Queue* queue) {
    if (queue_empty(queue)) {
        printf("E: queue empty\n");
    }
    // save the item at index start (we will need it later)
    int data = queue->data[queue->start];
    // increment the start index, looping back if necessary
    queue->start = (queue->start + 1) % queue->capacity;
    // then, return the saved data
    return data;
}
