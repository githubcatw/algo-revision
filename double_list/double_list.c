#include "double_list.h"
#include <stdlib.h>

DListNode* create_double_list_node(int value) {
    DListNode* node = (DListNode*)malloc(sizeof(DListNode));
    if (node) {
        node->value = value;
        node->next = NULL;
        node->prev = NULL;
    }
    return node;
}

DLinkedList* create_double_linked_list() {
    DLinkedList* list = (DLinkedList*)malloc(sizeof(DLinkedList));
    if (list) {
        list->head = NULL;
    }
    return list;
}

DListNode* dl_push_back(DLinkedList* list, int value) {
    // create a node
    DListNode* node = create_double_list_node(value);

    // if the list is empty, make this the root node
    if (list->head == NULL) {
        list->head = node;
    }
    // else, go until the end and add the new node after the last node
    else {
        DListNode* cur = list->head;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = node;
        // new! update the connection on the side of this node
        node->prev = cur;
    }

    return node;
}

DListNode* dl_prepend(DLinkedList* list, int value) {
    // create a node
    DListNode* node = create_double_list_node(value);
    // if there is no head, make the new node the head
    if (list->head == NULL) {
        list->head = node;
    } else {
        // insert the node after the head
        node->next = list->head;
        list->head->prev = node;
        // replace the head
        list->head = node;
    }

    return node;
}

DListNode* dl_insert_after(DListNode* previous, int value) {
    // create a node
    DListNode* node = create_double_list_node(value);
    // link previous->next and this node
    node->next = previous->next;
    previous->next->prev = node;
    // link previous and this node
    previous->next = node;
    node->prev = previous;

    return node;
}
