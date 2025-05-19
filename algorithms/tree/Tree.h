#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

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

void inorderTraversal(struct Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void printTreeUtil(struct Node *root, int space) {
    if (root == NULL) {
        return;
    }

    space += 10;
    printTreeUtil(root->right, space);
    printf("\n");

    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    printTreeUtil(root->left, space);
}

void printTree(struct Node *root) {
    printf("Estrutura da Árvore Binaria:\n");
    printTreeUtil(root, 0);
}

void freeTree(struct Node *root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
