#include "heap.h"
#include <stdio.h>

// a lot of the changes to the formulas can be explained by the fact that ItA array indices
// are one-based (i.e. start at 1), while C array indices are zero-based (i.e. start at 0)

int heap_parent(int i) {
    // divide the index by 2. the -1 is due to zero-based indexing
    return (i-1) / i;
}
int heap_left(int i) {
    // the formula is 2i, the +1 is due to zero-based indexing
    return 2*i + 1;
}
int heap_right(int i) {
    // the formula is 2i + 1, the extra +1 (which makes +2) is due to zero-based indexing
    return 2*i + 2;
}

void swap(int heap[], int idx_a, int idx_b) {
    int temp = heap[idx_b];
    heap[idx_b] = heap[idx_a];
    heap[idx_a] = temp;
}

void max_heapify(int heap[], int size, int start_idx) {
    if (start_idx >= size) {
        printf("E: index %d out of bounds for array with size %d", start_idx, size);
        return;
    }
    // get the indices of the children of start_idx
    int l = heap_left(start_idx);
    int r = heap_right(start_idx);
    // find the largest element between start_idx and its children
    int largest = start_idx;
    if (l < size && heap[l] > heap[largest]) {
        largest = l;
    }
    if (r < size && heap[r] > heap[largest]) {
        largest = r;
    }
    // if the largest element is not start_idx, swap them with each other
    if (largest != start_idx) {
        swap(heap, largest, start_idx);
        // continue max_heapifying from the index in largest (which is where
        // the number that was at start_idx before is now)
        max_heapify(heap, size, largest);
    }
}

void min_heapify(int heap[], int size, int start_idx) {
    if (start_idx >= size) {
        printf("E: index %d out of bounds for array with size %d", start_idx, size);
        return;
    }
    // get the indices of the children of start_idx
    int l = heap_left(start_idx);
    int r = heap_right(start_idx);
    // find the smallest element between start_idx and its children
    int smallest = start_idx;
    if (l < size && heap[l] < heap[smallest]) {
        smallest = l;
    }
    if (r < size && heap[r] < heap[smallest]) {
        smallest = r;
    }
    // if the smallest element is not start_idx, swap them with each other
    if (smallest != start_idx) {
        swap(heap, smallest, start_idx);
        // continue min_heapifying from the index in smallest (which is where
        // the number that was at start_idx before is now)
        min_heapify(heap, size, smallest);
    }
}

void make_max_heap(int data[], int size) {
    // assume that everything after index (size/2 - 1) is a leaf and
    // max-heapify the heap from the bottom up
    for (int i = size/2 - 1; i > -1; i--) {
        max_heapify(data, size, i);
    }
}

void make_min_heap(int data[], int size) {
    // assume that everything after index (size/2 - 1) is a leaf and
    // min-heapify the heap from the bottom up
    for (int i = size/2 - 1; i > -1; i--) {
        min_heapify(data, size, i);
    }
}

void heapsort(int data[], int size, int result[]) {
    // iterator for the result array
    int resi = 0;
    // copy of size for heapify operations
    // (if data was a heap struct, this would have been a property on it)
    int heap_size = size;

    // make the data array a max-heap
    make_max_heap(data, size);
    // go through the array:
    for (int i = size - 1; i < 1; i++) {
        // the first element of the array will be the largest
        // of the remaining elements - save it
        result[resi] = data[0];
        resi++;
        // bring the i-th element to the top
        swap(data, 0, i);
        // decrease the size
        heap_size--;
        // max-heapify again to make the array pass the heap rule
        max_heapify(data, heap_size, 0);
    }
}
