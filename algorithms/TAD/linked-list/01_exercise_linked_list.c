#include <stdio.h>
#include <malloc.h>

struct Product
{
    char name [40];
    int quantity;
} typedef Product;


struct Node
{
    Product product;
    struct Node *next;    
} typedef Node;


void insertProductHeadLinkedList(Node **tail, Product product){
    Node *newNode =  (Node *)malloc(sizeof(Node));
    newNode -> product = product;
    newNode -> next = *tail;
    *tail = newNode;
}

void insertProductTailLinkedList(Node **head, Product product) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->product = product;
    newNode->next = *head;
    *head = newNode;
}

int main() {
    Node *head = NULL;
    Product newProduct = {"Head Product", 100};

    insertProductTailLinkedList(&head, newProduct);

    Product products[5] = {
        {"Product 1", 10},
        {"Product 2", 20},
        {"Product 3", 30},
        {"Product 4", 40},
        {"Product 5", 50}
    };

    for (int i = 0; i < 5; i++) {
        insertProductHeadLinkedList(&head, products[i]);
    }

    printf("\nLista de produtos:\n");
    Node *current = head;
    while (current != NULL) {
        printf("Name: %s, Quantity: %d\n", current->product.name, current->product.quantity);
        current = current->next;
    }

    return 0;
}