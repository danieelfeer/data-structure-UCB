#include <stdio.h>

int main(){

    int arr[] = {9, 3, 2, 8, 1, 2, 5, 4};
    int array_size = sizeof(arr) / sizeof(arr[0]);
    int min, temp;

    for(int i = 0; i < array_size -1; i++){
        min = i;
        for(int j = i + 1; j < array_size; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        if(min != i){
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    for(int i = 0; i < array_size; i++){
        printf("%d \n", arr[i]);
    }

    return 0;
}