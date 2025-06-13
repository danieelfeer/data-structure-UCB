#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 20

typedef struct Student {
    char name[50];
    char birthDate[12];
    float grade;
} Student;

typedef struct Node {
    Student data;
    struct Node* next;
} Node;

typedef struct {
    Node* table[TABLE_SIZE];
} HashTable;

unsigned int hash_function(const char* name);
void insert_student(HashTable* ht, const char* name, const char* birthDate, float grade);
Student* search_student(HashTable* ht, const char* name);
void display_table(HashTable* ht);

unsigned int hash_function(const char* name) {
    unsigned int hash = 0;
    while (*name) {
        hash = (hash * 31) + *name;
        name++;
    }
    return hash % TABLE_SIZE;
}

void insert_student(HashTable* ht, const char* name, const char* birthDate, float grade) {
    unsigned int index = hash_function(name);
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    strcpy(new_node->data.name, name);
    strcpy(new_node->data.birthDate, birthDate);
    new_node->data.grade = grade;
    new_node->next = ht->table[index]; // Insert at head (external chaining)
    ht->table[index] = new_node;
}

Student* search_student(HashTable* ht, const char* name) {
    unsigned int index = hash_function(name);
    Node* current = ht->table[index];

    while (current) {
        if (strcmp(current->data.name, name) == 0) {
            return &current->data;
        }
        current = current->next;
    }
    return NULL;
}

void display_table(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Node* current = ht->table[i];
        while (current) {
            printf("[%s, %s, %.2f] -> ", current->data.name, current->data.birthDate, current->data.grade);
            current = current->next;
        }
        printf("NULL\n");
    }
}
