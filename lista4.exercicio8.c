#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_VETOR 10

void inicializaVetor(int *v, int tamanho) {
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        v[i] = rand() % 100 + 1;
    }
}

void percorreVetorComPonteiros(int *v, int tamanho) {
    int *inicio = v;
    int *fim = v + tamanho - 1;

    while (inicio <= fim) {
        printf("Inicio: %d, Fim: %d\n", *inicio, *fim);
        inicio++;
        fim--;
    }
}

int main() {
    int vetor[TAMANHO_VETOR];
    inicializaVetor(vetor, TAMANHO_VETOR);

    printf("Vetor gerado aleatoriamente:\n");
    for (int i = 0; i < TAMANHO_VETOR; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("\nPercorrendo o vetor com dois ponteiros:\n");
    percorreVetorComPonteiros(vetor, TAMANHO_VETOR);
    
    return 0;
}