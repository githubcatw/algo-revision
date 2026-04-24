#ifndef GRAPH_CAPACITY
#define GRAPH_CAPACITY 10
#endif

typedef struct {
    /**
     * adjacency matrix.
     *
     * in an unweighted graph (`weighted` is 0), `adj_matrix[x][y]` is 0
     * if there is no edge x <-> y, and 1 if there is such an edge.
     *
     * in a weighted graph (`weighted` is 1), if an edge x <-> y exists,
     * `adj_matrix[x][y]` will be equal to the weight of that edge.
     * if there is no such edge it will be 0.
     */
    int adj_matrix[GRAPH_CAPACITY][GRAPH_CAPACITY];
    /**
     * names of vertices
     */
    char vertex_names[GRAPH_CAPACITY];
    int size;
    /**
     * is this graph weighted?
     */
    int weighted;
} Graph;

Graph* create_graph(int size);
Graph* create_graph_weighted(int size);
void graph_connect(Graph* graph, int node_a, int node_b);
void graph_connect_weighted(Graph* graph, int node_a, int node_b, int weight);
