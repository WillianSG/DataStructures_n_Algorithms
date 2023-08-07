#include <cstdlib>
#include<iostream>

using namespace std;

typedef struct tree_node {	
	int value;
	struct tree_node *left_child;
    struct tree_node *right_child;
} NODE;

NODE *create_node(int value) {

    NODE *new_node = (NODE*)malloc(sizeof(NODE));

    new_node->value = value;
    new_node->left_child = NULL;
    new_node->right_child = NULL;

    return new_node;
}

void insert_node(NODE **root, NODE *new_node) {

    NODE **tree_tracer = root;

    // Traversing tree until leaf node (NULL) is found.
    while (*tree_tracer) {

        if ((*tree_tracer)->value > new_node->value) {

            tree_tracer = &(*tree_tracer)->left_child;

        } else {

            tree_tracer = &(*tree_tracer)->right_child;

        }
    }

    // Now '*tree_tracer' points to either the left or right child of a leaf node.
    *tree_tracer = new_node;
}

void DFS_traverse_preorder(NODE **root) {

    if (*root == NULL) {
        return;
    }

    cout << (*root)->value << '\n';

    DFS_traverse_preorder(&(*root)->left_child);        // Recursively access left subtree.

    DFS_traverse_preorder(&(*root)->right_child);       // Recursively access right subtree.
}

void DFS_traverse_inorder(NODE **root) {

    if (*root == NULL) {
        return;
    }

    DFS_traverse_inorder(&(*root)->left_child);        // Recursively access left subtree.

    cout << (*root)->value << '\n';

    DFS_traverse_inorder(&(*root)->right_child);       // Recursively access right subtree.

}

void DFS_traverse_postorder(NODE **root) {

    if (*root == NULL) {
        return;
    }

    DFS_traverse_postorder(&(*root)->left_child);        // Recursively access left subtree.

    DFS_traverse_postorder(&(*root)->right_child);       // Recursively access right subtree.

    cout << (*root)->value << '\n';

}

int main() {

    NODE *root = (NODE*)malloc(sizeof(NODE));
    root = NULL;

    insert_node(&root, create_node(4));
    insert_node(&root, create_node(3));
    insert_node(&root, create_node(7));
    insert_node(&root, create_node(8));
    insert_node(&root, create_node(1));
    insert_node(&root, create_node(5));

    cout << "In-order:\n";
    DFS_traverse_inorder(&root);

    cout << "Pre-order:\n";
    DFS_traverse_preorder(&root);

    cout << "Post-order:\n";
    DFS_traverse_postorder(&root);

}