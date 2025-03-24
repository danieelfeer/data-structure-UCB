#include <stdio.h>

struct Product {
    char name[40];
    int quantity;
    float price;
} typedef Product;

void merge(Product array[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Product L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = array[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = array[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].price <= R[j].price) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Product array[], int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;    
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}


int main (){

    Product products[] = {{"Tomato", 4, 8.20}, {"Banana", 1, 1.80}, {"Apple", 10, 16.90}, {"Grape", 2, 1.10}, {"Potato", 3, 3.12}};

    int size_arr = sizeof(products)/sizeof(products[0]); 
    int left_arr = 0;
    int right_arr = size_arr - 1;
    
    mergeSort(products, left_arr, right_arr);

    for (int i = 0; i < size_arr; i++) {
        printf("%s: %.2f\n", products[i].name, products[i].price);
    }

}