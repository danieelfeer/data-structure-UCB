#include "exercise_01.h"

int main() {
    struct Corredor *root = NULL;
    float tempoCorte;

    printf("Digite o tempo de corte: ");
    scanf("%f", &tempoCorte);

    // Inserção dos corredores
    root = insertCorredor(root, "Roberto", 12.5, tempoCorte);
    root = insertCorredor(root, "Caio", 15.2, tempoCorte);
    root = insertCorredor(root, "Joao", 11.8, tempoCorte);
    root = insertCorredor(root, "Maria", 14.1, tempoCorte);
    root = insertCorredor(root, "Jorge", 10.5, tempoCorte);

    printf("\nCorredores classificados:\n");
    printClassificados(root);

    freeTree(root);
    return 0;
}
