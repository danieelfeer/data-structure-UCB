#include "Tree.h"

int main() {
    struct Node* root = NULL;
    
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 90);
    root = insert(root, 10);
    root = insert(root, 100);
    
    printf("Percorrer da Arvore de Busca Binaria (ordenado): ");
    inorderTraversal(root);
    printf("\n");
    
    printTree(root);
    
    freeTree(root);
    root = NULL;
    
    return 0;
}
