#define DSU_MAX_NODES 10

typedef struct {
    /**
     * indices of representative nodes of the given data node.
     *
     * in other words, reps[i] is the index of the node in data that represents data[i].
     */
    int reps[DSU_MAX_NODES];
    /**
     * the data stored in this list.
     */
    int data[DSU_MAX_NODES];
    /*
     * the rank of every disjoint set.
     */
    int ranks[DSU_MAX_NODES];
    /**
     * the amount of data in the entire DSU.
     */
    int size;
} DisjointSets;

DisjointSets* create_sets(int data[], int size);
int find_set(DisjointSets* ds, int index);
void union_sets(DisjointSets* ds, int index_a, int index_b);
