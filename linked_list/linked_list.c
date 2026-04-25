#include "linked_list.h"
#include <stdlib.h>

SListNode* create_single_list_node(int value) {
    SListNode* node = (SListNode*)malloc(sizeof(SListNode));
    if (node) {
        node->value = value;
        node->next = NULL;
    }
    return node;
}

SLinkedList* create_single_linked_list() {
    SLinkedList* list = (SLinkedList*)malloc(sizeof(SLinkedList));
    if (list) {
        list->head = NULL;
    }
    return list;
}

SListNode* sl_push_back(SLinkedList* list, int value) {
    // create a node
    SListNode* node = create_single_list_node(value);

    // if the list is empty, make this the root node
    if (list->head == NULL) {
        list->head = node;
    }
    // else, go until the end and add the new node after the last node
    else {
        SListNode* cur = list->head;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = node;
    }

    return node;
}

SListNode* sl_prepend(SLinkedList* list, int value) {
    // create a node
    SListNode* node = create_single_list_node(value);
    // if there is no head, make the new node the head
    if (list->head == NULL) {
        list->head = node;
    } else {
        // insert the node after the head
        node->next = list->head;
        // replace the head
        list->head = node;
    }
    return node;
}

SListNode* sl_insert_after(SListNode* previous, int value) {
    // create a node
    SListNode* node = create_single_list_node(value);
    // insert the node between previous and its next
    node->next = previous->next;
    previous->next = node;

    return node;
}
