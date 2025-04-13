#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Music
{
    char name [80];
    char artist [80];
    struct Music *next;
    struct Music *prev;
} typedef Music;

void insertAtBeginning(Music **head, const char *name, const char *artist);
void insertAtEnd(Music **head, const char *name, const char *artist);
void printPlaylist(Music *head);
Music* moveForward(Music *current);
Music* moveBackward(Music *current);

int main() {
    Music *head = NULL;

    insertAtBeginning(&head, "Bohemian Rhapsody", "Queen");
    insertAtBeginning(&head, "Imagine", "John Lennon");
    insertAtEnd(&head, "Let It Be", "The Beatles");
    insertAtEnd(&head, "Stairway to Heaven", "Led Zeppelin");

    printPlaylist(head);

    Music *currentlyPlaying = head;
    if (currentlyPlaying != NULL) {
        printf("\nCurrently playing: '%s' by %s\n", currentlyPlaying->name, currentlyPlaying->artist);
    }

    currentlyPlaying = moveForward(currentlyPlaying);
    if (currentlyPlaying != NULL) {
        printf("Next music: '%s' by %s\n", currentlyPlaying->name, currentlyPlaying->artist);
    }

    currentlyPlaying = moveBackward(currentlyPlaying);
    if (currentlyPlaying != NULL) {
        printf("Going back to: '%s' by %s\n", currentlyPlaying->name, currentlyPlaying->artist);
    }

    return 0;
}

void insertAtBeginning(Music **head, const char *name, const char *artist){
    Music *newMusic = (Music *)malloc(sizeof(Music));
    
    strcpy(newMusic->name, name);
    strcpy(newMusic->artist, artist);

    newMusic->next = *head;
    newMusic->prev = NULL;

    if(*head != NULL)(*head)->prev = newMusic;

    *head = newMusic;
}

void insertAtEnd(Music **head, const char *name, const char *artist){
    Music *newMusic = (Music *)malloc(sizeof(Music));

    strcpy(newMusic->name, name);
    strcpy(newMusic->artist, artist);
    
    newMusic->next = NULL;

    if(*head != NULL){
        newMusic->prev = NULL;
        *head = newMusic;
        return;
    }

    Music *current = *head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newMusic;
    newMusic->prev = current;
    
}

void printPlaylist(Music *head) {
    Music *current = head;
    printf("Playlist (forward): ");
    while (current != NULL) {
        printf("'%s' by %s <-> ", current->name, current->artist);
        current = current->next;
    }
    printf("NULL\n");
}

Music* moveForward(Music *current) {
    if (current != NULL) {
        return current->next;
    }
    return NULL;
}

Music* moveBackward(Music *current) {
    if (current != NULL) {
        return current->prev;
    }
    return NULL;
}