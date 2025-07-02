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

    printf("Tabela de distancias sem repeticoes:\n");

    for (int i = 0; i < linha; i++) {
        for (int j = i + 1; j < coluna; j++) {
            printf("Distancia entre cidade %d e cidade %d: %d km\n", i+1, j+1, matriz[i][j]);
        }
    }

    return 0;
}
