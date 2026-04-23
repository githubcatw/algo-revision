#ifndef GRAPH_CAPACITY
#define GRAPH_CAPACITY 10
#endif

typedef struct {
    /**
     * adjacency matrix
     */
    int adj_matrix[GRAPH_CAPACITY][GRAPH_CAPACITY];
    /**
     * names of vertices
     */
    char vertex_names[GRAPH_CAPACITY];
    int size;
} Graph;

Graph* create_graph(int size);
void graph_connect(Graph* graph, int node_a, int node_b);
