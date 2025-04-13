#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CARRIAGES 10

typedef struct Carriage {
    int people;
    char color[20];
    struct Carriage *next;
    struct Carriage *prev;
} Carriage;

void initializeGiantWheel(Carriage **head);
void rotateClockwise(Carriage **head);
void rotateCounterClockwise(Carriage **head);
void board(Carriage *head, int index, int people);
void disembark(Carriage *head, int index, int people);
void printWheel(Carriage *head);

int main() {
    Carriage *head = NULL;
    initializeGiantWheel(&head);

    int choice, index, people;
    
    while (1) {
        printf("\n----- Giant Wheel -----\n");
        printf("1. Rotate Clockwise\n");
        printf("2. Rotate Counterclockwise\n");
        printf("3. Board\n");
        printf("4. Disembark\n");
        printf("5. Show Giant Wheel\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                rotateClockwise(&head);
                break;
            case 2:
                rotateCounterClockwise(&head);
                break;
            case 3:
                printf("Choose a carriage (0 to 9): ");
                scanf("%d", &index);
                printf("How many people will board? ");
                scanf("%d", &people);
                board(head, index, people);
                break;
            case 4:
                printf("Choose a carriage (0 to 9): ");
                scanf("%d", &index);
                printf("How many people will disembark? ");
                scanf("%d", &people);
                disembark(head, index, people);
                break;
            case 5:
                printWheel(head);
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}

void initializeGiantWheel(Carriage **head) {
    const char *colors[] = {
        "Red", "Blue", "Green", "Yellow", "Pink", "Orange", "Black", "White", "Gray", "Brown"
    };
    
    Carriage *newCarriage, *temp;
    *head = NULL;

    for (int i = 0; i < NUM_CARRIAGES; i++) {
        newCarriage = (Carriage *)malloc(sizeof(Carriage));
        newCarriage->people = 0;
        strcpy(newCarriage->color, colors[i]);

        if (*head == NULL) {
            *head = newCarriage;
            newCarriage->next = *head;
            newCarriage->prev = *head;
        } else {
            temp = *head;
            while (temp->next != *head) {
                temp = temp->next;
            }
            temp->next = newCarriage;
            newCarriage->prev = temp;
            newCarriage->next = *head;
            (*head)->prev = newCarriage;
        }
    }
}

void rotateClockwise(Carriage **head) {
    if (*head != NULL) {
        *head = (*head)->next;
        printf("The wheel rotated clockwise.\n");
    }
}

void rotateCounterClockwise(Carriage **head) {
    if (*head != NULL) {
        *head = (*head)->prev;
        printf("The wheel rotated counterclockwise.\n");
    }
}

void board(Carriage *head, int index, int people) {
    if (head == NULL) return;

    Carriage *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    current->people += people;
    printf("Boarded %d people on carriage %d (%s).\n", people, index, current->color);
}

void disembark(Carriage *head, int index, int people) {
    if (head == NULL) return;

    Carriage *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    if (current->people >= people) {
        current->people -= people;
        printf("Disembarked %d people from carriage %d (%s).\n", people, index, current->color);
    } else {
        printf("Not enough people to disembark from carriage %d (%s).\n", index, current->color);
    }
}

void printWheel(Carriage *head) {
    if (head == NULL) {
        printf("The giant wheel is empty.\n");
        return;
    }

    Carriage *current = head;
    printf("Giant Wheel - Carriages:\n");

    do {
        printf("Carriage %d (%s): %d people\n", current->people, current->color, current->people);
        current = current->next;
    } while (current != head);

    printf("\n");
}
