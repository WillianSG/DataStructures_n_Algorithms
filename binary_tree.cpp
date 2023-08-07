#include <cstdlib>
#include <iostream>

using namespace std;

#include "data_types/BST.h"

int main() {

    NODE *root = (NODE*)malloc(sizeof(NODE));
    root = NULL;

    insertNode(&root, creatNode(4));
    // insertNode(&root, creatNode(3));
    insertNode(&root, creatNode(7));
    insertNode(&root, creatNode(8));
    // insertNode(&root, creatNode(1));
    // insertNode(&root, creatNode(5));

    cout << "In-order:\n";
    dfsInorder(&root);

    cout << "Pre-order:\n";
    dfsPreorder(&root);

    cout << "Post-order:\n";
    dfsPostorder(&root);

    deleteNode(&root, 4);

    cout << "Pre-order:\n";
    dfsPreorder(&root);

    // freeMemory(&root);
}