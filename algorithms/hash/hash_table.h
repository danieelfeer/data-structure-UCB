#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Student {
    char name[50];
    char birthDate[12];
    float grade;
    struct Student* next;
} Student;

typedef struct {
    Student* table[TABLE_SIZE];
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
    Student* new_student = (Student*)malloc(sizeof(Student));
    if (!new_student) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(new_student->name, name);
    strcpy(new_student->birthDate, birthDate);
    new_student->grade = grade;
    new_student->next = ht->table[index];
    ht->table[index] = new_student;
}

Student* search_student(HashTable* ht, const char* name) {
    unsigned int index = hash_function(name);
    Student* current = ht->table[index];

    while (current) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void display_table(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Student* current = ht->table[i];
        while (current) {
            printf("[%s, %s, %.2f] -> ", current->name, current->birthDate, current->grade);
            current = current->next;
        }
        printf("NULL\n");
    }
}

