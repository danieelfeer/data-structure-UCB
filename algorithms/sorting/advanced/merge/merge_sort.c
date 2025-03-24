#include <stdio.h>
// Função para mesclar duas metades ordenadas
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    // Copiando os elementos para os arrays temporários
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    // Merge dos arrays temporários
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copia os elementos restantes de L[], se houver
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copia os elementos restantes de R[], se houver
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// Função recursiva do Merge Sort
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main()
{
    int arr[100] = {35, 23, 56, 9, 46, 90, 55, 96, 44, 80, 59, 21, 14, 83, 85, 17,
                    34,
                    50, 16, 41, 8, 58, 64, 1, 33, 49, 88, 13, 99, 69, 66, 76, 95, 60, 86, 37, 53, 48, 71,
                    10, 29, 61, 97, 51, 22, 91, 78, 25, 42, 93, 68, 94, 18, 6, 28, 82, 70, 73, 4, 79, 62,
                    52, 43, 19, 77, 7, 40, 67, 75, 92, 81, 20, 72, 100, 11, 74, 38, 32, 65, 2, 98, 27,
                    30,
                    47, 3, 54, 26, 39, 24, 87, 84, 89, 15, 45, 12, 63, 36, 57, 5, 31};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, size - 1);
    printf("Array ordenado: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}