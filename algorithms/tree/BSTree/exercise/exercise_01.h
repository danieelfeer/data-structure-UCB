#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do corredor
struct Corredor {
    char nome[50];
    float tempo;
    struct Corredor *left;
    struct Corredor *right;
};

// Função para criar um novo corredor
struct Corredor *createCorredor(char *nome, float tempo) {
    struct Corredor *newCorredor = (struct Corredor *)malloc(sizeof(struct Corredor));
    strcpy(newCorredor->nome, nome);
    newCorredor->tempo = tempo;
    newCorredor->left = NULL;
    newCorredor->right = NULL;
    return newCorredor;
}

// Função para inserir um corredor na árvore
struct Corredor *insertCorredor(struct Corredor *root, char *nome, float tempo, float tempoCorte) {
    if (root == NULL) {
        return createCorredor(nome, tempo);
    }

    if (tempo < tempoCorte) {
        root->right = insertCorredor(root->right, nome, tempo, tempoCorte);
    } else {
        root->left = insertCorredor(root->left, nome, tempo, tempoCorte);
    }

    return root;
}

// Função para imprimir corredores classificados
void printClassificados(struct Corredor *root) {
    if (root != NULL) {
        printClassificados(root->right);
        printf("Nome: %s | Tempo: %.2f\n", root->nome, root->tempo);
        printClassificados(root->left);
    }
}

// Função para liberar a memória da árvore
void freeTree(struct Corredor *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

