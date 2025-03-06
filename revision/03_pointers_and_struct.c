#include <stdio.h>

struct Person {
    char name[20];
    int age;
    float height;
} typedef Person;

void createPerson();
void printPerson();
void AddAge();
void AddHeight();

int main(){
    Person person;

    createPerson(&person);

    addAge(&person);
    addAge(&person);
    addHeight(&person);
    addHeight(&person);
    addHeight(&person);

    printPerson(person);
    return 0;
}

void createPerson(Person* person){
    printf("name: ");
    scanf("%s", &person->name);

    printf("age: ");
    scanf("%d", &person->age);

    printf("height: ");
    scanf("%f", &person->height);
}

void printPerson(Person person) {
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Height: %.2f\n", person.height);
}

void addAge(Person* person){
    person->age++;
}

void addHeight(Person* person){
    person->height += 0.01;
}
