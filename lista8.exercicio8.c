#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void bubbleSort(char *vetor, int tam) {
    char temp;
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

void quickSort(char *vetor, int esquerda, int direita) {
    int i = esquerda;
    int j = direita;
    char pivo = vetor[(esquerda + direita) / 2];

    while (i <= j) {
        while (vetor[i] < pivo) i++;
        while (vetor[j] > pivo) j--;
        if (i <= j) {
            char temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
            i++;
            j--;
        }
    }
    if (esquerda < j)
        quickSort(vetor, esquerda, j);
    if (i < direita)
        quickSort(vetor, i, direita);
}

int compararChar(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int main() {
    char vetor[MAX];
    printf("Digite uma string: ");
    fgets(vetor, MAX, stdin);
    vetor[strcspn(vetor, "\n")] = '\0';
    int tam = strlen(vetor);
    char copiaBubble[MAX], copiaQuick[MAX], copiaQsort[MAX];
    strcpy(copiaBubble, vetor);
    strcpy(copiaQuick, vetor);
    strcpy(copiaQsort, vetor);
    bubbleSort(copiaBubble, tam);
    quickSort(copiaQuick, 0, tam - 1);
    qsort(copiaQsort, tam, sizeof(char), compararChar);
    printf("\nOriginal:     %s", vetor);
    printf("\nBubble Sort:  %s", copiaBubble);
    printf("\nQuickSort:    %s", copiaQuick);
    printf("\nqsort():      %s\n", copiaQsort);
    return 0;
}
