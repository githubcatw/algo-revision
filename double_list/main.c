#include <stdio.h>
#include "double_list.h"

void dl_print(DLinkedList* list) {
    DListNode* cur = list->head;
    // iterate through the list
    while(cur) {
        printf("%d", cur->value);
        // if there is a next, print an arrow
        if (cur->next) {
            printf(" --> ");
        }
        cur = cur->next;
    }
}

int main() {
    DLinkedList* list = create_double_linked_list();

    dl_push_back(list, 2);
    DListNode* three = dl_push_back(list, 3);
    dl_push_back(list, 8);
    dl_push_back(list, 13);

    dl_insert_after(three, 5);

    dl_print(list);
}
