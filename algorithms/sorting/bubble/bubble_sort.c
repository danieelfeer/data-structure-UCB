#include <stdio.h>
int main()
{
    int arr[] = {5, 4, 6, 3, 2, 9, 1};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    int i, j, temp, trocou;
    for (i = 0; i < tamanho - 1; i++)
    {
        trocou = 0;
        for (j = 0; j < tamanho - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                trocou = 1;
            }
        }
        if (trocou == 0)
        {
            break; // Se não houve troca, a lista já está ordenada
        }
    }
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}