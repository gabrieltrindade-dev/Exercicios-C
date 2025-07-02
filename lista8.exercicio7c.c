#include <stdio.h>
#define linha 5
#define coluna 5

int main() {
    int matriz[linha][coluna] = {
        { 0, 15, 30,  5, 12},
        {15,  0, 10, 17, 28},
        {30, 10,  0,  3, 11},
        { 5, 17,  3,  0, 80},
        {12, 28, 11, 80,  0},
    };

    int n, percurso[100], total = 0;

    printf("Quantas cidades no percurso? ");
    scanf("%d", &n);

    printf("Digite as cidades do percurso (numeros entre 1 e 5):\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &percurso[i]);
        if(percurso[i] < 1 || percurso[i] > 5){
            printf("Cidade invalida! Digite valores entre 1 e 5.\n");
            i--;
        }
    }

    for(int i = 0; i < n - 1; i++) {
        int c1 = percurso[i];
        int c2 = percurso[i + 1];
        total += matriz[c1 - 1][c2 - 1];
    }

    printf("Total percorrido: %d km\n", total);

    return 0;
}
