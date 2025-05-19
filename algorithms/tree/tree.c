#include "Tree.h"

int main() {
    struct Node *root = NULL;

    root = insertNode(root, 1);
    root = insertNode(root, 2);
    root = insertNode(root, 3);
    root = insertNode(root, 4);
    root = insertNode(root, 5);
    root = insertNode(root, 6);
    root = insertNode(root, 8);

    printf("Percorrendo a árvore: ");
    inorderTraversal(root);
    printf("\n");

    printTree(root);
    freeTree(root);

    return 0;
}
