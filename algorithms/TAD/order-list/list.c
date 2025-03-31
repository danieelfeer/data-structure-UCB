#include <stdio.h>
#include "order_list.c"

int main()
{
    int tamanho = 0;
    int vetor[100];
    inserirOrdenado(10, &tamanho, vetor);
    inserirOrdenado(5, &tamanho, vetor);
    inserirOrdenado(15, &tamanho, vetor);
    inserirOrdenado(2, &tamanho, vetor);
    printf("Vetor ordenado: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    return 0;
}