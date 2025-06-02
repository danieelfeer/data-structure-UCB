#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    char name[50];
    int quantity;
    float price;
} Product;

typedef struct TreeNode {
    Product product;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createTreeNode(Product product) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Error allocating memory for node!\n");
        exit(1);
    }
    newNode->product = product;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insertIntoTree(TreeNode* root, Product product) {
    if (root == NULL) {
        return createTreeNode(product);
    }

    if (strcmp(product.name, root->product.name) < 0) {
        root->left = insertIntoTree(root->left, product);
    } else if (strcmp(product.name, root->product.name) > 0) {
        root->right = insertIntoTree(root->right, product);
    }

    return root;
}

TreeNode* searchInTree(TreeNode* root, char* searchedName) {
    if (root == NULL) {
        printf("Product '%s' not found in stock.\n", searchedName);
        return NULL;
    }

    if (strcmp(searchedName, root->product.name) == 0) {
        printf("Product '%s' found! Quantity: %d.\n", root->product.name, root->product.quantity);
        return root;
    }

    if (strcmp(searchedName, root->product.name) < 0) {
        return searchInTree(root->left, searchedName);
    } else {
        return searchInTree(root->right, searchedName);
    }
}

void printInOrder(TreeNode* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("Product: %s | Quantity: %d | Price: %.2f\n", root->product.name, root->product.quantity, root->product.price);
        printInOrder(root->right);
    }
}

void freeTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
