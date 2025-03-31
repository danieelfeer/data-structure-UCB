#include <stdio.h>

struct Student
{
    char name[50];
    int age;
    int serie;
    int registration_number;
} typedef Student;

void insertOrdered(Student value, int *array_size, Student array[])
{
    if (*array_size >= 100)
    {
        printf("array full!\n");
        return;
    }
    int i = *array_size - 1;
    while (i >= 0 && array[i].registration_number > value.registration_number)
    {
        array[i + 1] = array[i];
        i--;
    }
    array[i + 1] = value;
    (*array_size)++;
}

void removeStudent(int registration_number, int *array_size, Student array[])
{
    int index = -1;

    for (int i = 0; i < *array_size; i++)
    {
        if (array[i].registration_number == registration_number)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("Student %d not found.\n", registration_number);
        return;
    }

    for (int i = index; i < *array_size - 1; i++)
    {
        array[i] = array[i + 1];
    }

    (*array_size)--;

    printf("Student %d removed.\n", registration_number);
}



int main()
{

    Student students[20];
    int array_size = 0;

    Student student1 = {"Ana Silva", 15, 9, 1002};
    Student student2 = {"Bruno Costa", 16, 10, 1001};
    Student student3 = {"Carla Mendes", 14, 8, 1005};
    Student student4 = {"Daniel Souza", 17, 11, 1004};
    Student student5 = {"Elisa Ferreira", 18, 12, 1003};

    insertOrdered(student1, &array_size, students);
    insertOrdered(student2, &array_size, students);
    insertOrdered(student3, &array_size, students);
    insertOrdered(student4, &array_size, students);
    insertOrdered(student5, &array_size, students);
    
    removeStudent(1005, &array_size, students);

    
    for (int i = 0; i < array_size; i++)
    {
        printf("Name: %s, Age: %d, Series: %d, Registration Number: %d\n",
               students[i].name, students[i].age, students[i].serie, students[i].registration_number);
    }
    

    return 0;
}