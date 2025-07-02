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

    int cidade1, cidade2;

    while (1) {
        printf("\nDigite o numero da cidade 1 (1 a 5, ou 0 para encerrar): ");
        scanf("%d", &cidade1);

        printf("Digite o numero da cidade 2 (1 a 5, ou 0 para encerrar): ");
        scanf("%d", &cidade2);

        if (cidade1 == 0 && cidade2 == 0) {
            printf("fim\n");
            break;
        }

        if (cidade1 < 1 || cidade1 > 5 || cidade2 < 1 || cidade2 > 5) {
            printf("Cidades inválidas! Digite valores entre 1 e 5.\n");
            continue;
        }

        int dist = matriz[cidade1 - 1][cidade2 - 1];
        printf("Distancia da cidade %d ate a cidade %d eh de %d km.\n", cidade1, cidade2, dist);
    }

    return 0;
}