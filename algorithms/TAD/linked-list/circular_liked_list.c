#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Function declarations
void insertAtBeginningCircular(Node **head, int value);
void insertAtEndCircular(Node **head, int value);

int main() {
    Node *head = NULL;

    // Inserting values into the circular linked list
    insertAtEndCircular(&head, 5);
    insertAtBeginningCircular(&head, 3);
    insertAtEndCircular(&head, 7);
    insertAtBeginningCircular(&head, 1);

    // Checking if the list is empty
    if (head == NULL) {
        printf("Empty list.\n");
    } else {
        Node *current = head;
        printf("Circular Linked List: ");
        
        // Traversing the circular linked list
        do {
            printf("%d -> ", current->data);
            current = current->next;
        } while (current != head); // Will loop back to the head
        
        printf("(back to head)\n");
    }

    return 0;
}

// Function definitions

void insertAtBeginningCircular(Node **head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        Node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}

void insertAtEndCircular(Node **head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        Node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}
