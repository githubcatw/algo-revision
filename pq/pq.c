#include "pq.h"
#include<stdlib.h>
#include<stdio.h>

MinPQ* create_pq(int size) {
    MinPQ* pq = (MinPQ*)malloc(sizeof(MinPQ));
    if (pq) {
        pq->size = 0;
        // initialize all 3 arrays
        for (int i = 0; i < size; i++) {
            pq->heap[i] = i;
            pq->keys[i] = 0;
            pq->pos[i] = i;
        }
    }
    // return the pq
    return pq;
}
void pq_swap(MinPQ* pq, int idx_a, int idx_b) {
    // first, swap the cached positions
    pq->pos[pq->heap[idx_a]] = idx_b;
    pq->pos[pq->heap[idx_b]] = idx_a;

    // then, swap the values inside heap
    int temp = pq->heap[idx_a];
    pq->heap[idx_a] = pq->heap[idx_b];
    pq->heap[idx_b] = temp;

    // finally, swap the keys
    temp = pq->keys[idx_a];
    pq->keys[idx_a] = pq->keys[idx_b];
    pq->keys[idx_b] = temp;
}

int pq_left(int i)   {return 2*i + 1;}
int pq_parent(int i) {return (i-1)/2;}
int pq_right(int i)  {return 2*i + 2;}

void decrease_key(MinPQ* pq, int value, int new_key) {
    // find the index of the requested vertex in the heap
    // (this is where we need pos)
    int index = pq->pos[value];
    // save its new key
    pq->keys[index] = new_key;
    // keep swapping it up until its key is not more than the parent's
    while (index >= 0 && pq->keys[pq_parent(index)] > new_key) {
        pq_swap(pq, index, pq_parent(index));
        // update the index to check
        index = pq_parent(index);
    }
}

void pq_push(MinPQ* pq, int value, int key) {
    // check if the pq is at capacity
    if (pq->size == PQ_CAPACITY) {
        printf("E: priority queue at capacity\n");
        return;
    }
    // update the size
    pq->size++;
    // insert the new value and set a temporary key
    pq->heap[pq->size - 1] = value;
    pq->pos[value] = pq->size - 1;
    pq->keys[pq->size - 1] = 100000000;
    // decrease its key to the proper one
    decrease_key(pq, value, key);
}

void min_heapify(MinPQ* pq, int start_idx) {
    // return early if the heap only has one element or is empty
    if (pq->size <= 1) {
        return;
    }
    // boundary check
    if (start_idx < 0 || start_idx >= pq->size) {
        printf("E: index out of bounds; needs to be %d < %d < %d\n", 0, start_idx, pq->size);
        return;
    }
    // get left and right
    int l = pq_left(start_idx);
    int r = pq_right(start_idx);
    // find the smallest
    int smallest = start_idx;
    if (l < pq->size && pq->keys[l] < pq->keys[smallest]) {
        smallest = l;
    }
    if (r < pq->size && pq->keys[r] < pq->keys[smallest]) {
        smallest = r;
    }
    // if the smallest isn't the root, swap them and min-heapify the rest
    if (smallest != start_idx) {
        pq_swap(pq, smallest, start_idx);
        min_heapify(pq, start_idx);
    }
}

int pq_pop(MinPQ* pq) {
    // check if the pq is empty
    if (pq->size == 0) {
        printf("E: priority queue is empty\n");
        return -1;
    }
    // save the value of the top element
    int saved_value = pq->heap[0];
    // swap the last and top elements
    pq_swap(pq, 0, pq->size - 1);
    // decrease the size
    pq->size--;
    // min-heapify to make sure that the heap rule is preserved
    min_heapify(pq, 0);
    // return the saved value
    return saved_value;
}
