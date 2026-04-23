#include<stdlib.h>
#include<stdio.h>
#include "bintree.h"

Node* create_node(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    // init if the malloc succeeds
    if (node) {
        node->key = key;
        node->left = NULL;
        node->right = NULL;
    }
    // return the node
    return node;
}

Node* insert_node(Node* tree_root, Node* node) {
    // if the current root is null, return the node the user wants to insert
    // as the new root (this is the base case)
    if (tree_root == NULL) {
        return node;
    }
    // if the node is null, return the tree root (just in case)
    if (node == NULL) {
        return tree_root;
    }
    // find out where the node should go
    if (node->key < tree_root->key) {
        // node is smaller than root -> go left recursively
        tree_root->left = insert_node(tree_root->left, node);
    } else {
        // node is larger or equal to root -> go right recursively
        tree_root->right = insert_node(tree_root->right, node);
    }
    // return the processed tree root
    return tree_root;
}

Node* insert_number(Node* tree_root, int key) {
    return insert_node(tree_root, create_node(key));
}

void print_inorder(Node* tree_root) {
    if (tree_root == NULL) {
        return;
    }

    // inorder = left, parent, right (LPR)
    // recursively print the left node
    print_inorder(tree_root->left);
    // print this node
    printf("%d ", tree_root->key);
    // recursively print the right node
    print_inorder(tree_root->right);
}

void print_preorder(Node* tree_root) {
    if (tree_root == NULL) {
        return;
    }

    // preorder = parent, left, right (PLR)
    // print this node
    printf("%d ", tree_root->key);
    // recursively print the left node
    print_preorder(tree_root->left);
    // recursively print the right node
    print_preorder(tree_root->right);
}

void print_postorder(Node* tree_root) {
    if (tree_root == NULL) {
        return;
    }

    // postorder = left, right, parent (LRP)
    // recursively print the left node
    print_postorder(tree_root->left);
    // recursively print the right node
    print_postorder(tree_root->right);
    // print this node
    printf("%d ", tree_root->key);
}
