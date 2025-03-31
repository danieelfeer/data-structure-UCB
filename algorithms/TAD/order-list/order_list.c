#define list.h  

void inserirOrdenado(int valor, int *tamanho, int vetor[]) {
if (*tamanho >= 100) {
printf("Vetor cheio!\n");
return;
}
int i = *tamanho - 1;
while (i >= 0 && vetor[i] > valor) {
vetor[i + 1] = vetor[i];
i--;
}
vetor[i + 1] = valor;
(*tamanho)++;
}