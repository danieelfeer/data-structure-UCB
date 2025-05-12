#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Patient structure
typedef struct Patient {
    char name[100]; 
    char cpf[15];    
    int severity;   
    struct Patient *next;
} Patient;

// Queue structure
typedef struct Queue {
    Patient *front;
    Patient *rear;
} Queue;

// Initialize queue
void initializeQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

// Check if the queue is empty
bool isEmpty(Queue *q) {
    return q->front == NULL;
}

// Add a patient to the queue
void enqueue(Queue *q, char *name, char *cpf, int severity) {
    Patient *newPatient = (Patient*) malloc(sizeof(Patient));
    strcpy(newPatient->name, name);
    strcpy(newPatient->cpf, cpf);
    newPatient->severity = severity;
    newPatient->next = NULL;

    printf("Adding patient: %s (Severity: %d)\n", name, severity);

    if (isEmpty(q)) {
        q->front = newPatient;
        q->rear = newPatient;
    } else {
        q->rear->next = newPatient;
        q->rear = newPatient;
    }
}

// Remove a patient from the queue
Patient* dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Error: The queue is empty!\n");
        return NULL;
    }

    Patient *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    return temp; // Return the removed patient
}

// Print the queue contents
void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("The queue is empty.\n");
        return;
    }

    printf("Patients in queue:\n");
    Patient *current = q->front;
    while (current != NULL) {
        printf("Name: %s, CPF: %s, Severity: %d\n", current->name, current->cpf, current->severity);
        current = current->next;
    }
}

// Free allocated memory for the queue
void freeQueue(Queue *q) {
    Patient *current = q->front;
    while (current != NULL) {
        Patient *next = current->next;
        free(current);
        current = next;
    }
    q->front = NULL;
    q->rear = NULL;
}

// Hospital queues
Queue emergencyQueue;
Queue icuQueue;
Queue triageQueue;

// Add a patient based on severity
void addPatient(char *name, char *cpf, int severity) {
    if (severity >= 8) {
        enqueue(&emergencyQueue, name, cpf, severity);
    } else if (severity >= 5) {
        enqueue(&icuQueue, name, cpf, severity);
    } else {
        enqueue(&triageQueue, name, cpf, severity);
    }
}

int main() {
    initializeQueue(&emergencyQueue);
    initializeQueue(&icuQueue);
    initializeQueue(&triageQueue);

    // Add patients
    addPatient("João Silva", "123.456.789-00", 9);
    addPatient("Maria Souza", "987.654.321-00", 6);
    addPatient("Carlos Santos", "456.789.123-00", 3);

    // Print queues
    printf("\nEmergency Queue:\n");
    printQueue(&emergencyQueue);

    printf("\nICU Queue:\n");
    printQueue(&icuQueue);

    printf("\nTriage Queue:\n");
    printQueue(&triageQueue);

    // Free allocated memory
    freeQueue(&emergencyQueue);
    freeQueue(&icuQueue);
    freeQueue(&triageQueue);

    return 0;
}
