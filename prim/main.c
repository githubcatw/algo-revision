#include <limits.h>
#include<stdio.h>
#include<stdlib.h>
#include "../graph/graph.h"
#include "../pq/pq.h"

void prim(Graph* graph, int start_idx) {
    // create a priority queue for the vertices
    MinPQ* pq = create_pq(graph->size);

    // add the start vertex with key 0 and every other vertex with key INT_MAX
    for (int i = 0; i < graph->size; i++) {
        if (i == start_idx) {
            pq_push(pq, i, 0);
        } else {
            pq_push(pq, i, INT_MAX);
        }
    }

    // until the queue is emptied:
    while (pq->size > 0) {
        // pop the vertex with the smallest key
        int vertex = pq_pop(pq);

        // print the name of the vertex we just popped
        printf("%c ", graph->vertex_names[vertex]);

        // check the vertices that are adjacent to it
        for (int i = 0; i < graph->size; i++) {
            if (graph->adj_matrix[vertex][i] != 0) {
                // check its key against the one stored in the pq
                if (pq->keys[pq->pos[i]] > graph->adj_matrix[vertex][i]) {
                    // if there is a new shortest path to that vertex, update its key
                    decrease_key(pq, i, graph->adj_matrix[vertex][i]);
                }
            }
        }
    }
}

int main() {
    Graph* graph = create_graph_weighted(4);
    // add some nodes
    for (int i = 0; i < 4; i++) {
        // 0x41 is "A"; this is a fast way to get the alphabet
        graph->vertex_names[i] = 0x41 + i;
    }

    /**
     * the graph:
     *
     *   A - 2 - B
     *   |     / |
     *  13   3   8
     *   | /     |
     *   C - 5 - D
     */

    // connect them!
    graph_connect_weighted(graph, 0, 1, 2);
    graph_connect_weighted(graph, 2, 1, 3);
    graph_connect_weighted(graph, 3, 2, 5);
    graph_connect_weighted(graph, 3, 1, 8);
    graph_connect_weighted(graph, 0, 2, 13);

    // run prim's algorithm
    prim(graph, 0);
}
