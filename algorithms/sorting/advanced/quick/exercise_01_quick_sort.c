#include <stdio.h>

struct Car{
    char name[40];
    char brand[40];
    int horsepower;
} typedef Car;


// Quick Sort
void quick_sort(Car *array, int start, int end) {
	
    if (start < end) {
		int q = partition(array, start, end);
		quick_sort(array, start, q - 1);
		quick_sort(array, q + 1, end);
	}
}
// Partition by pivot
int partition(Car *array, int start, int end) {
	int pivot = array[end].horsepower;
	int i = start - 1;
	Car temp;
	for (int j = start; j < end; j++) {
		if (array[j].horsepower <= pivot) {
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = temp;

	return i + 1;
}

int main(void) {

    Car cars[] = {
        {"X5", "BMW", 300},
        {"Q7", "Audi", 250},
        {"GLE", "Mercedes", 350},
        {"Model X", "Tesla", 450},
        {"Explorer", "Ford", 200},
        {"Tahoe", "Chevrolet", 220},
        {"Land Cruiser", "Toyota", 180}
    };

    int size = sizeof(cars) / sizeof(cars[0]);
    quick_sort(cars, 0, size - 1);

	// Print result
	for (int i = 0; i < 4; i++) {
		printf("%s ", cars[i].name);
		printf("%s ", cars[i].brand);
		printf("%d \n", cars[i].horsepower);

	}

	return 0;
}