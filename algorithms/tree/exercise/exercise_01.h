#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Função para criar um novo nó
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um nó na árvore (sem ordenação)
struct Node *insertNode(struct Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    static int side = 0;
    if (side == 0) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    side = 1 - side;

    return root;
}

// Função para percorrer a árvore e imprimir os valores
void inorderTraversal(struct Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Função para buscar um número na árvore e imprimir o caminho até ele
int searchNode(struct Node *root, int target, char *path) {
    if (root == NULL) {
        return 0;  // Número não encontrado
    }

    if (root->data == target) {
        return 1;  // Número encontrado
    }

    if (searchNode(root->left, target, path)) {
        sprintf(path + strlen(path), " -> E");
        return 1;
    } else if (searchNode(root->right, target, path)) {
        sprintf(path + strlen(path), " -> D");
        return 1;
    }

    return 0;
}

// Função para imprimir o caminho até o número ou a árvore completa
void findNumberOrPrintTree(struct Node *root, int target) {
    char path[100] = "Raiz";

    if (searchNode(root, target, path)) {
        printf("Caminho encontrado: %s -> %d\n", path, target);
    } else {
        printf("Número não encontrado! Exibindo a árvore completa:\n");
        inorderTraversal(root);
        printf("\n");
    }
}

// Função para liberar a memória da árvore
void freeTree(struct Node *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
