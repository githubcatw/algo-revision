#include "../queue/queue.h"
#include "../graph/graph.h"
#include "../stack/stack.h"
#include <stdio.h>

void print_queue(Queue* queue) {
    for (int i = 0; i < queue->capacity; i++) {
        if (queue->start == i && queue->end == i) {
            printf("{");
        } else if (queue->end == i) {
            printf("(");
        } else if (queue->start == i) {
            printf("[");
        } else {
            printf(" ");
        }
        printf("%d", queue->data[i]);
        if (queue->start == i && queue->end == i) {
            printf("}");
        } else if (queue->end == i) {
            printf(")");
        } else if (queue->start == i) {
            printf("]");
        } else {
            printf(" ");
        }
        printf(" ");
    }
}

void bfs(Graph* graph, int start_idx) {
    // visited[i] shows if vertex i has been visited
    int visited[graph->size];
    // backing array for the queue
    int backing[graph->size];
    // fill both arrays in one loop
    // (you can write this as 2 loops, it shouldn't impact time complexity)
    for (int i = 0; i < graph->size; i++) {
        visited[i] = 0;
        backing[i] = 0;
    }
    // create a queue
    Queue* queue = create_queue(backing, graph->size);

    // enqueue the starting index
    enqueue(queue, start_idx);

    // keep on dequeueing until the queue is empty
    while (!queue_empty(queue)) {
        int current = dequeue(queue);
        // mark the vertex as visited
        visited[current] = 1;

        // now we're free to do anything with this vertex!
        // in this case print its name:
        printf("%c ", graph->vertex_names[current]);

        // enqueue every vertex it's adjacent to, unless that vertex has been visited
        for (int i = 0; i < graph->size; i++) {
            int is_adjacent = graph->adj_matrix[current][i];
            if (!visited[i] && is_adjacent) {
                enqueue(queue, i);
                //print_queue(queue);
            }
        }
    }
}

void dfs(Graph* g, int start_idx) {
    // the dfs algorithm has the same steps as the bfs algorithm,
    // except it uses a stack instead of a queue.

    // keep track of the vertices that we have visited
    int visited[g->size];
    // backing array for the stack
    int backing[g->size];
    // fill both arrays in one loop
    // (you can write this as 2 loops, it shouldn't impact time complexity)
    for (int i = 0; i < g->size; i++) {
        visited[i] = 0;
        backing[i] = 0;
    }

    // create a stack
    Stack* s = create_stack(backing, g->size);

    // push the starting node
    stack_push(s, start_idx);

    // pop until the stack is empty
    while (!stack_empty(s)) {
        int src = stack_pop(s);

        // mark it as visited
        visited[src] = 1;

        // now we're once again free to do anything with the vertex
        // here we'll once again print its name
        printf("%c ", g->vertex_names[src]);

        // push all of its adjacent vertices that we haven't been to yet
        for (int i = 0; i < g->size; i++) {
            if (g->adj_matrix[src][i] && !visited[i]) {
                stack_push(s, i);
            }
        }
    }
}

int main() {
    // the graph:
    //            A
    //          / | \
    //         B  C  D
    //       / |     | \
    //      E  F     G  H

    // names of vertices
    char names[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    // create a graph
    Graph* g = create_graph(8);
    // copy the names
    for (int i = 0; i < 8; i++) {
        g->vertex_names[i] = names[i];
    }
    // connect everything
    graph_connect(g, 0, 1);
    graph_connect(g, 0, 2);
    graph_connect(g, 0, 3);
    graph_connect(g, 1, 4);
    graph_connect(g, 1, 5);
    graph_connect(g, 3, 6);
    graph_connect(g, 3, 7);

    // run bfs
    printf("BFS: ");
    bfs(g, 0);

    // run dfs
    printf("\nDFS: ");
    dfs(g, 0);
}
