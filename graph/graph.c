#include "graph.h"
#include<stdlib.h>
#include<stdio.h>

Graph* create_graph(int size) {
    if (size > GRAPH_CAPACITY) {
        printf("E: a graph may have %d nodes at most\n", GRAPH_CAPACITY);
        return NULL;
    }
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (graph) {
        graph->size = size;
        // initialize adjacency matrix
        for (int x = 0; x < size; x++) {
            for (int y = 0; y < size; y++) {
                graph->adj_matrix[x][y] = 0;
            }
        }
    }
    return graph;
}

void graph_connect(Graph* graph, int node_a, int node_b) {
    // bound checking
    if (node_a >= graph->size) {
        printf("E: node_a index out of range\n");
        return;
    }
    if (node_b >= graph->size) {
        printf("E: node_b index out of range\n");
        return;
    }

    // create the connection
    graph->adj_matrix[node_a][node_b] = 1;
    // since this is an impl of an undirected graph, create the opposite connection
    graph->adj_matrix[node_b][node_a] = 1;
}
