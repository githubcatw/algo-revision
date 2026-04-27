#include "../double_list/double_list.h"
#include<stdio.h>

void print_from(DListNode* end) {
    while (end) {
        printf("%d", end->value);

        // if there is a next, print an arrow
        if (end ->next){
            printf(" <-> ");
        }

        end = end->next;
    }
    printf("\n");
}

DListNode* merge(DListNode* start_a, DListNode* start_b) {
    printf("merging ");
    print_from(start_a);
    printf("and ");
    print_from(start_b);
    // keep temporary pointer for the current node
    DListNode* cur = NULL;
    // starting node of the result
    DListNode* start = NULL;
    // until one of the pointers reaches null:
    while (start_a != NULL && start_b != NULL) {
        // compare start_a and start_b. whichever node wins gets linked to cur
        if (start_a->value < start_b->value) {
            printf("%d < %d\n", start_a->value, start_b->value);
            // if cur is null, start_a IS cur
            if (cur == NULL) {
                printf("created cur %d\n", start_a->value);
                cur = start_a;
                // also update start, it might be null too
                start = start_a;
            }
            // else, link it to be after cur
            else {
                cur->next = start_a;
                start_a->prev = cur;
            }
            // now, advance start_a and cur
            cur = start_a;
            start_a = start_a->next;
        }
        // default to linking start_b if equal
        else {
            printf("%d >= %d\n", start_a->value, start_b->value);
            // if cur is null, start_b IS cur
            if (cur == NULL) {
                printf("created cur %d\n", start_b->value);
                cur = start_b;
                // also update start, it might be null too
                start = start_b;
            }
            // else, link it to be after cur
            else {
                start_b->prev = cur;
                cur->next = start_b;
                printf("cur next should be start_b = %d. test: %d\n", start_b->value, cur->next->value);
            }
            // now, advance start_b and cur
            cur = start_b;
            start_b = start_b->next;
        }
    }
    // finally, link whichever pointer is not null to be after cur
    // (this mirrors the "copy the remaining array" step of mergesort)
    printf("merging step of mergesort done! printing from start");
    print_from(start);
    if (start_a == NULL) {
        printf("start_a is NULL");
    } else {
        printf("start_a is %d", start_a->value);
    }
    if (start_b == NULL) {
        printf(", start_b is NULL");
    } else {
        printf(", start_b is %d", start_b->value);
    }
    printf(", cur is %d", cur->value);
    printf("\n");

    if (start_a != NULL) {
        start_a->prev = cur;
        cur->next = start_a;
    } else {
        start_b->prev = cur;
        cur->next = start_b;
    }
    printf("mergesort done! printing from start");
    print_from(start);
    // all that's left is to return the start
    return start;
}

DListNode* find_middle(DListNode* start, DListNode* end) {
    // for this we need 2 pointers: a fast one and a slow one.
    DListNode* fast = start->next;
    DListNode* slow = start;
    // until we reach the end on fast:
    while (fast != end && fast != NULL) {
        // try to advance 2 points further:
        if (fast->next) {
            fast = fast->next->next;
        } else {
            fast = fast->next;
        }
        // advance slow
        slow = slow->next;
    }
    // at the end, slow will get to the middle of the list
    return slow;
}

DListNode* do_merge_sort(DListNode* start, DListNode* end) {
    // quit if boundary nodes are the same
    if (start == end) {
        return start;
    }
    // find the middle of the list
    DListNode* middle = find_middle(start, end);
    // keep the next node
    DListNode* middleNext = middle->next;
    // unlink middle and middleNext from each other, thereby separating the list
    middle->next = NULL;
    middleNext->prev = NULL;
    // divide the list into 2 and call mergesort on both halves
    // update the pointers because they might change as part of merge()
    start = do_merge_sort(start, middle);
    middleNext = do_merge_sort(middleNext, end);
    // finally, merge the two lists
    return merge(start, middleNext);
}

void merge_sort(DLinkedList* list) {
    // find the end of the list
    DListNode* end = list->head;
    while (end && end->next) {
        end = end->next;
    }
    // run the mergesort algorithm from head to end
    DListNode* new_head = do_merge_sort(list->head, end);
    // update the head
    list->head = new_head;
}

int main() {
    DLinkedList* list = create_double_linked_list();
    dl_prepend(list, 5);
    dl_prepend(list, 13);
    dl_prepend(list, 2);
    dl_prepend(list, 8);
    dl_prepend(list, 3);
    dl_prepend(list, 21);

    // now sort the list:
    merge_sort(list);

    // finally, print it
    DListNode* end = list->head;
}
