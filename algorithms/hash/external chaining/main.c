#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

int main() {
    HashTable ht = {0};

    insert_student(&ht, "Alice", "2000-05-12", 89.5);
    insert_student(&ht, "Bob", "1999-11-23", 75.0);
    insert_student(&ht, "Charlie", "2001-07-30", 92.3);
    insert_student(&ht, "David", "2002-02-14", 88.0);
    insert_student(&ht, "Eve", "1998-08-21", 79.5);
    insert_student(&ht, "Frank", "2003-12-01", 85.0);
    insert_student(&ht, "Grace", "2004-07-08", 91.2);
    insert_student(&ht, "Hank", "1997-06-03", 83.7);
    insert_student(&ht, "Ivy", "2000-09-09", 90.1);
    insert_student(&ht, "Jack", "2001-11-15", 87.4);
    insert_student(&ht, "Karen", "1995-04-10", 78.2);
    insert_student(&ht, "Leo", "2003-01-27", 89.9);
    insert_student(&ht, "Mia", "1996-05-05", 92.0);
    insert_student(&ht, "Noah", "2002-10-30", 80.3);
    insert_student(&ht, "Olivia", "1994-12-29", 88.8);
    insert_student(&ht, "Peter", "1999-07-17", 86.5);
    insert_student(&ht, "Quinn", "2005-03-12", 77.3);
    insert_student(&ht, "Ryan", "2004-08-02", 84.1);
    insert_student(&ht, "Sophia", "2001-06-06", 90.9);
    insert_student(&ht, "Tom", "1998-09-23", 82.7);

    display_table(&ht);

    Student* found = search_student(&ht, "Mia");
    if (found) {
        printf("Found: %s, %s, %.2f\n", found->name, found->birthDate, found->grade);
    } else {
        printf("Student not found!\n");
    }

    return 0;
}
