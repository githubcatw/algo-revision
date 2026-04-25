#define DOUBLE_LIST_H

typedef struct DListNode {
    int value;
    struct DListNode* next;
    struct DListNode* prev;
} DListNode;

typedef struct {
    struct DListNode* head;
} DLinkedList;

DListNode* create_double_list_node(int value);
DLinkedList* create_double_linked_list();
DListNode* dl_prepend(DLinkedList* list, int value);
DListNode* dl_push_back(DLinkedList* list, int value);
DListNode* dl_insert_after(DListNode* previous, int value);
