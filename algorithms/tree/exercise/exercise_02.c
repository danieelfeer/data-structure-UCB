#include "exercise_02.h"

int main() {
    TreeNode* root = NULL;
    Product p1 = {"Rice", 10, 5.99};
    Product p2 = {"Beans", 20, 7.50};
    Product p3 = {"Pasta", 15, 4.30};
    Product p4 = {"Oil", 8, 9.90};

    root = insertIntoTree(root, p1);
    root = insertIntoTree(root, p2);
    root = insertIntoTree(root, p3);
    root = insertIntoTree(root, p4);

    printf("\nProducts in stock:\n");
    printInOrder(root);

    printf("\nSearching for product 'Beans':\n");
    searchInTree(root, "Beans");

    freeTree(root);

    return 0;
}
