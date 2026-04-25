#define LINKED_LIST_H

typedef struct SListNode {
    int value;
    struct SListNode* next;
} SListNode;

typedef struct {
    struct SListNode* head;
} SLinkedList;

SListNode* create_single_list_node(int value);
SLinkedList* create_single_linked_list();
SListNode* sl_push_back(SLinkedList* list, int value);
SListNode* sl_prepend(SLinkedList* list, int value);
SListNode* sl_insert_after(SListNode* previous, int value);
