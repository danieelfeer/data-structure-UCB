#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

int main() {
    HashTable ht = {0};

    insert_student(&ht, "Alice", "2000-05-12", 89.5);
    insert_student(&ht, "Bob", "1999-11-23", 75.0);
    insert_student(&ht, "Charlie", "2001-07-30", 92.3);

    display_table(&ht);

    Student* found = search_student(&ht, "Bob");
    if (found) {
        printf("Found: %s, %s, %.2f\n", found->name, found->birthDate, found->grade);
    } else {
        printf("Student not found!\n");
    }

    return 0;
}
