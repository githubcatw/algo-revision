// if graph capacity is defined (i.e. whatever file is including this
// also includes graph.h), use it as the capacity of the priority queue

#ifdef GRAPH_CAPACITY
#define PQ_CAPACITY GRAPH_CAPACITY
#else
#define PQ_CAPACITY 10
#endif

typedef struct {
    /**
     * array on which heap operations will be performed.
     */
    int heap[PQ_CAPACITY];
    /**
     * the keys of vertices stored inside heap.
     */
    int keys[PQ_CAPACITY];
    /**
     * inverse of heap[], as in, pos[i] is the index of the vertex named i in heap.
     */
    int pos[PQ_CAPACITY];
    /**
     * size of this priority queue.
     */
    int size;
} MinPQ;

MinPQ* create_pq(int size);

int pq_left(int i);
int pq_parent(int i);
int pq_right(int i);

void pq_swap(MinPQ* pq, int idx_a, int idx_b);
void pq_push(MinPQ* pq, int value, int key);
void min_heapify(MinPQ* pq, int start_idx);
void decrease_key(MinPQ* pq, int value, int new_key);
int pq_pop(MinPQ* pq);
