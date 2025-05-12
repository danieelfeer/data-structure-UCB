// Stack.h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of the linked list node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Definition of the stack structure
typedef struct {
    Node *top; // Pointer to the top of the stack
} Stack;

// Initializes an empty stack
void initializeStack(Stack *s) {
    s->top = NULL;
}

// Checks if the stack is empty
bool isEmpty(Stack *s) {
    return s->top == NULL;
}

// Returns the top element of the stack without removing it
int top(Stack *s) {
    if (isEmpty(s)) {
        printf("Error: The stack is empty!\n");
        return -1; // Error value
    }
    return s->top->data;
}

// Stack.h
// Adds an element to the top of the stack (push)
void push(Stack *s, int value) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = s->top; // The new node points to the old top
    s->top = newNode; // The stack top is now the new node
}

// Removes and returns the top element of the stack (pop)
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Error: The stack is empty!\n");
        return -1; // Error value
    }
    Node *temp = s->top; // Temporary pointer to the top
    int value = temp->data;
    s->top = s->top->next; // The top is now the next node
    free(temp); // Free memory of the removed node
    return value;
}

// Stack.h
// Prints the contents of the stack (from top to bottom)
void printStack(Stack *s) {
    if (isEmpty(s)) {
        printf("The stack is empty.\n");
        return;
    }
    printf("Stack (top -> bottom): [");
    Node *current = s->top;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(", ");
        }
        current = current->next;
    }
    printf("]\n");
}

// Frees the allocated memory for the stack
void freeStack(Stack *s) {
    Node *current = s->top;
    Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    s->top = NULL;
}


int main() {
    Stack myStack;
    initializeStack(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printStack(&myStack); // Output: Stack (top -> bottom): [30, 20, 10]

    printf("Pop: %d\n", pop(&myStack)); // Output: Pop: 30
    printStack(&myStack); // Output: Stack (top -> bottom): [20, 10]

    printf("Peek: %d\n", top(&myStack)); // Output: Peek: 20

    push(&myStack, 40);
    printStack(&myStack); // Output: Stack (top -> bottom): [40, 20, 10]

    printf("Pop: %d\n", pop(&myStack)); // Output: Pop: 40
    printf("Pop: %d\n", pop(&myStack)); // Output: Pop: 20

    printStack(&myStack); // Output: Stack (top -> bottom): [10]

    printf("Pop: %d\n", pop(&myStack)); // Output: Pop: 10
    printStack(&myStack); // Output: The stack is empty.

    printf("Pop: %d\n", pop(&myStack)); // Output: Error: The stack is empty! -1

    freeStack(&myStack); // Free allocated memory

    return 0;
}
