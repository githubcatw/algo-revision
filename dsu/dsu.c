#include "dsu.h"
#include<stdlib.h>
#include<stdio.h>

DisjointSets* create_sets(int data[], int size) {
    if (size > DSU_MAX_NODES) {
        printf("too many nodes\n");
        return NULL;
    }
    DisjointSets* dsu = (DisjointSets*)malloc(sizeof(DisjointSets));
    if (dsu) {
        dsu->size = size;
        // insert every piece of data into dsu, at the start
        // every node is its own representative
        for (int i = 0; i < size; i++) {
            dsu->data[i] = data[i];
            dsu->reps[i] = i;
            dsu->ranks[i] = 0;
        }
    }
    return dsu;
}

int find_set(DisjointSets* ds, int index) {
    // go back recursively, finding representatives until
    // we reach the root of the set
    if (ds->reps[index] != index) {
        ds->reps[index] = find_set(ds, ds->reps[index]);
    }

    // once the root is found, return it!
    return ds->reps[index];
}

void union_sets(DisjointSets* ds, int index_a, int index_b) {
    if (index_a >= ds->size) {
        printf("E: index A out of range\n");
        return;
    }
    if (index_b >= ds->size) {
        printf("E: index B out of range\n");
        return;
    }

    // find the sets of both nodes
    int rep_a = find_set(ds, index_a);
    int rep_b = find_set(ds, index_b);

    // if they're the same, do nothing
    if (rep_a == rep_b) {
        return;
    }

    // merge the larger set into the smaller by changing
    // the representative of the representative of the smaller set.
    // "but how do we know which set is larger?" well, using ranks
    if (ds->ranks[rep_a] > ds->ranks[rep_b]) {
        ds->reps[rep_b] = rep_a;
    } else if (ds->ranks[rep_b] > ds->ranks[rep_a]) {
        ds->reps[rep_a] = rep_b;
    }
    // if the lists have the same rank, increase that rank.
    else {
        ds->ranks[rep_a]++;
        ds->ranks[rep_b]++;
        // now merge one of the sets, chosen arbitrarily, into the other:
        ds->reps[rep_a] = rep_b;
    }
}
