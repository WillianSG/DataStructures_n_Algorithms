#ifndef MYFILE_H_
#define MYFILE_H_

typedef struct tree_node {	
	int value;
	struct tree_node *left_child;
    struct tree_node *right_child;
} NODE;

NODE *creatNode(int value) {

    NODE *new_node = (NODE*)malloc(sizeof(NODE));

    new_node->value = value;
    new_node->left_child = NULL;
    new_node->right_child = NULL;

    return new_node;
}

void insertNode(NODE **root, NODE *new_node) {

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

void deleteNode(NODE **root, int value) {

    NODE **target_node = root;
    NODE *parent_node = NULL;

    // Traversing tree until leaf node (NULL) is found.
    while (*target_node && (*target_node)->value != value) {

        parent_node = *target_node;

        if ((*target_node)->value > value) {

            target_node = &(*target_node)->left_child;

        } else {

            target_node = &(*target_node)->right_child;

        }
    }

    if (parent_node == NULL) {
        // Deleting root.

        if ((*root)->left_child) {

            NODE *aux_right = (*root)->right_child;

            *root = (*root)->left_child;

            (*root)->right_child = aux_right;

        } else if ((*root)->right_child) {

            *root = (*root)->right_child;
        } else {
            *root = NULL;
        }

    } else if (parent_node->value < value) {

        if ((*target_node)->left_child == (*target_node)->right_child && (*target_node)->right_child == NULL) {
            
            parent_node->right_child = NULL;
        } else {

            if ((*target_node)->left_child) {
                // Node on the left will take place of deleted node.

                NODE *aux_right = (*target_node)->right_child;

                parent_node->right_child = (*target_node)->left_child;

                parent_node->right_child->right_child = aux_right;

            } else if ((*target_node)->right_child) {
                // Node on the right will take place of deleted node.

                parent_node->right_child = (*target_node)->right_child;
            }
        }

    } else {

        if ((*target_node)->left_child == (*target_node)->right_child && (*target_node)->right_child == NULL) {
           
            parent_node->left_child = NULL;
        } else {

            if ((*target_node)->left_child) {
                // Node on the left will take place of deleted node.

                NODE *aux_right = (*target_node)->right_child;

                parent_node->left_child = (*target_node)->left_child;

                parent_node->left_child->right_child = aux_right;

            } else if ((*target_node)->right_child) {
                // Node on the right will take place of deleted node.
                
                parent_node->right_child = (*target_node)->right_child;
            }
        }
    }
}

void dfsInorder(NODE **root) {

    if (*root == NULL) {
        return;
    }

    dfsInorder(&(*root)->left_child); 

    cout << (*root)->value << '\n';

    dfsInorder(&(*root)->right_child);

}

void dfsPreorder(NODE **root) {

    if (*root == NULL) {
        return;
    }

    cout << (*root)->value << '\n';

    dfsPreorder(&(*root)->left_child); 

    dfsPreorder(&(*root)->right_child);
}

void dfsPostorder(NODE **root) {

    if (*root == NULL) {
        return;
    }

    dfsPostorder(&(*root)->left_child); 

    dfsPostorder(&(*root)->right_child);

    cout << (*root)->value << '\n';

}

void freeMemory(NODE **root) {

    if (*root == NULL) {
        return;
    }

    freeMemory(&(*root)->left_child); 

    freeMemory(&(*root)->right_child);

    free(*root);

}

#endif