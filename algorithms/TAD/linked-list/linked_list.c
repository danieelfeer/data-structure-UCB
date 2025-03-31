#define linked_list.h

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insertAtBeginning(Node **head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}
