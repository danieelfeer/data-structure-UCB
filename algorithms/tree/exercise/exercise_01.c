#include "exercise_01.h"

int main() {
    struct Node *root = NULL;

    // Inserção de números na árvore
    root = insertNode(root, 1);
    root = insertNode(root, 2);
    root = insertNode(root, 3);
    root = insertNode(root, 4);
    root = insertNode(root, 5);
    root = insertNode(root, 6);
    root = insertNode(root, 8);

    int target;
    printf("Digite um numero para buscar na arvore: ");
    scanf("%d", &target);

    findNumberOrPrintTree(root, target);

    freeTree(root);
    return 0;
}