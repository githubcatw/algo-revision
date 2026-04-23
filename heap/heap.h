// a heap can be represented as an array (though it's a bit more difficult),
// so there is no need to implement a new struct

int heap_parent(int i);
int heap_left(int i);
int heap_right(int i);

void swap(int heap[], int idx_a, int idx_b);

void max_heapify(int heap[], int size, int start_idx);
void make_max_heap(int data[], int size);

void min_heapify(int heap[], int size, int start_idx);
void make_min_heap(int data[], int size);
void heapsort(int data[], int size, int result[]);
