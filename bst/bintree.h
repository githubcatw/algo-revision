typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int key);
Node* insert_node(Node* tree_root, Node* node);
Node* insert_number(Node* tree_root, int key);

void print_inorder(Node* tree_root);
void print_preorder(Node* tree_root);
void print_postorder(Node* tree_root);
