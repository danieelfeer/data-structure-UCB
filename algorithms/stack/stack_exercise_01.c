#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for mathematical operations
typedef struct Operation {
    double num1; 
    double num2; 
    char operation; 
    double result;
    struct Operation *next;
} Operation;

// Stack structure for storing operations
typedef struct {
    Operation *top; // Pointer to the top of the stack
} Stack;

// Initializes the stack
void initializeStack(Stack *s) {
    s->top = NULL;
}

// Checks if the stack is empty
bool isEmpty(Stack *s) {
    return s->top == NULL;
}

// Push an operation onto the stack
void push(Stack *s, double num1, double num2, char operation) {
    Operation *newOp = (Operation*) malloc(sizeof(Operation));
    newOp->num1 = num1;
    newOp->num2 = num2;
    newOp->operation = operation;

    // Perform the calculation
    switch (operation) {
        case '+': newOp->result = num1 + num2; break;
        case '-': newOp->result = num1 - num2; break;
        case '*': newOp->result = num1 * num2; break;
        case '/': 
            if (num2 == 0) {
                printf("Error: Division by zero!\n");
                free(newOp);
                return;
            }
            newOp->result = num1 / num2;
            break;
        default: 
            printf("Error: Invalid operation!\n");
            free(newOp);
            return;
    }

    newOp->next = s->top;
    s->top = newOp;

    printf("Operation performed: %.2f %c %.2f = %.2f\n", num1, operation, num2, newOp->result);
}

// Remove the last operation from the stack
void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Error: No operations to remove.\n");
        return;
    }

    Operation *temp = s->top;
    printf("Removing last operation: %.2f %c %.2f = %.2f\n",
           temp->num1, temp->operation, temp->num2, temp->result);

    s->top = s->top->next;
    free(temp);
}

// Print the operation history
void printStack(Stack *s) {
    if (isEmpty(s)) {
        printf("No operations in history.\n");
        return;
    }

    printf("\nOperation history:\n");
    Operation *current = s->top;
    while (current != NULL) {
        printf("%.2f %c %.2f = %.2f\n", current->num1, current->operation, current->num2, current->result);
        current = current->next;
    }
}

// Free allocated memory for the stack
void freeStack(Stack *s) {
    while (!isEmpty(s)) {
        pop(s);
    }
}

int main() {
    Stack history;
    initializeStack(&history);

    push(&history, 10, 5, '+');
    push(&history, 20, 4, '-');
    push(&history, 3, 7, '*');
    push(&history, 8, 2, '/');
    
    printStack(&history); // Display operation history

    pop(&history); // Remove the last operation

    printStack(&history); // Display updated history

    freeStack(&history); // Free memory

    return 0;
}
