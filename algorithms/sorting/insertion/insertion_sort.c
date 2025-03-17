#include <stdio.h>
int main()
{
    int arr[] = {5, 3, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i, chave, j;
    for (i = 1; i < n; i++){
        chave = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
