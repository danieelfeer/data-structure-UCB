#include <stdio.h>
#include <stdlib.h>
#include "linked_list.c"

int main() {
    Node *head = NULL; 
    int size = 0;         
    int array[100];   

    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 8);

    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    
    return 0;
}
