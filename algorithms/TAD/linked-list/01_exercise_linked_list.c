#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Product
{
    char name[40];
    int quantity;
} typedef Product;

struct Node
{
    Product product;
    struct Node *next;
} typedef Node;

Node* createNode(Product product)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->product = product;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node **head, Product product)
{
    Node* newNode = createNode(product);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node **head, Product product)
{
    Node* newNode = createNode(product);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    
    Node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node *head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        printf("Products: %s | Quantity: %d\n", temp->product.name, temp->product.quantity);
       temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;

    Product p1 = {"Rice", 10};
    Product p2 = {"Beans", 5};
    Product p3 = {"Pasta", 7};
    Product p4 = {"Meat", 2};

    insertAtEnd(&head, p1); 
    insertAtBeginning(&head, p2);
    insertAtEnd(&head, p3); 
    insertAtBeginning(&head, p4);

    printf("List:\n");
    printList(head);
    Node* temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
