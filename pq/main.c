#include "pq.h"
#include<stdio.h>

int main() {
    MinPQ* pq = create_pq(5);
    //pq_push(pq, 8, 8);
    //pq_push(pq, 2, 2);
    //pq_push(pq, 3, 3);
    //pq_push(pq, 5, 5);

    pq_push(pq, 0, 1);
    pq_push(pq, 1, 2);
    pq_push(pq, 2, 3);
    pq_push(pq, 3, 4);

    while (pq->size > 0) {
        printf("%d ", pq_pop(pq));
    }
}
