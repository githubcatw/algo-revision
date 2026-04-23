#include "bintree.h"
#include<stdio.h>

int main() {
    Node* root_fib = create_node(5);
    insert_number(root_fib, 2);
    insert_number(root_fib, 3);
    insert_number(root_fib, 8);
    insert_number(root_fib, 13);
    insert_number(root_fib, 21);

    printf("inorder: ");
    print_inorder(root_fib);
    printf("\npreorder: ");
    print_preorder(root_fib);
    printf("\npostorder: ");
    print_postorder(root_fib);
}
