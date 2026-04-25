#include <stdio.h>
#include "linked_list.h"

void sl_print(SLinkedList* list) {
    SListNode* cur = list->head;
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
    SLinkedList* list = create_single_linked_list();

    sl_push_back(list, 2);
    SListNode* three = sl_push_back(list, 3);
    sl_push_back(list, 8);
    sl_push_back(list, 13);

    sl_insert_after(three, 5);

    sl_print(list);
}
