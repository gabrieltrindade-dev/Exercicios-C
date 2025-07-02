#include <stdio.h>
#define linha 8
#define coluna 8

int main(){
    int matriz[linha][coluna] = {
        {1, 3, 0, 5, 4, 0, 2, 1},
        {1, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 6, 0},
        {1, 0, 0, 1, 1, 0, 0, 1},
        {0, 1, 0, 4, 0, 0, 1, 0},
        {0, 0, 3, 1, 0, 0, 1, 1},
        {1, 0, 6, 6, 0, 0, 1, 0},
        {1, 0, 5, 0, 1, 1, 0, 6},
    };
    int contPeaoEBispo=0, contVazio=0;
    for(int i=0; i<linha;i++){
        for(int j=0; j<coluna;j++){
            if(matriz[i][j]==1||matriz[i][j]==4){
                contPeaoEBispo++;
            }
            else if(matriz[i][j]==0){
                contVazio++;
            }
        }
    }
    printf("Quantidade de Peoes e Bispos: %d\n", contPeaoEBispo);
    printf("Quantidade de lugares sem pecas: %d", contVazio);
    return 0;
}