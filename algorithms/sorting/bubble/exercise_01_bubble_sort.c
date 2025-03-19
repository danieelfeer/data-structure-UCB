#include <stdio.h>

struct Person {
    char name[40];
    int age;
} typedef Person;


int main(){
    
    Person persons[4] = {{"Daniel", 19}, {"Mateus", 21}, {"Bruno", 30}, {"Guilherme", 20}};

    int array_size = sizeof(persons) / sizeof(persons[0]);
    Person temp;
    int swapped;

    for(int i = 0; i < array_size - 1; i++){
        swapped = 0;
        for(int j = 0; j < array_size - i - 1; j++ ){
            if(persons[j].age > persons[j+1].age){
                temp = persons[j];
                persons[j] = persons[j + 1];
                persons[j+1] = temp;
                swapped = 1;  
            }        
        }
        if(swapped == 0){
                break;
            }
    }

    for (int i = 0; i < array_size; i++) {
        printf("Name: %s\nAge: %d\n", persons[i].name, persons[i].age);
    }

    return 0;
}