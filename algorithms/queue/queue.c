#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Definition of the queue structure
typedef struct Queue {
    Node *front; // Pointer to the front of the queue
    Node *rear;  // Pointer to the end of the queue
} Queue;

// Initializes an empty queue
void initializeQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

// Checks if the queue is empty
bool isEmpty(Queue *q) {
    return q->front == NULL;
}

// Returns the front element of the queue without removing it (peek)
int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Error: The queue is empty!\n");
        return -1; // Error value
    }
    return q->front->data;
}

// Adds an element to the end of the queue (enqueue)
void enqueue(Queue *q, int value) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    printf("Enqueuing: %d\n", value);
    
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Removes and returns the front element of the queue (dequeue)
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Error: The queue is empty!\n");
        return -1; // Error value
    }
    
    Node *temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    free(temp);
    
    // If the queue becomes empty after dequeuing
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    return value;
}

// Queue.h
// Prints the contents of the queue
void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("The queue is empty.\n");
        return;
    }
    printf("Queue: [");
    Node *current = q->front;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(", ");
        }
        current = current->next;
    }
    printf("]\n");
}

// Frees the allocated memory for the queue
void freeQueue(Queue *q) {
    Node *current = q->front;
    Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    q->front = NULL;
    q->rear = NULL;
}

int main() {
    Queue queue;
    initializeQueue(&queue);
    
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    
    printQueue(&queue); // Output: Queue: [10, 20, 30]
    
    printf("Dequeuing: %d\n", dequeue(&queue)); // Output: Dequeue: 10
    
    printQueue(&queue); // Output: Queue: [20, 30]
    
    enqueue(&queue, 40);
    enqueue(&queue, 50);
    
    printQueue(&queue); // Output: Queue: [20, 30, 40, 50]
    
    printf("Peek: %d\n", peek(&queue)); // Output: Peek: 20
    printf("Dequeuing: %d\n", dequeue(&queue)); // Output: Dequeue: 20
    
    printQueue(&queue); // Output: Queue: [30, 40, 50]
    
    freeQueue(&queue); // Important to free allocated memory
    
    return 0;
}

