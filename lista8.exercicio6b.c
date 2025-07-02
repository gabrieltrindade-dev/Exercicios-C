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
    int contP=0, contA=0, contC=0, contRei=0,contRainha=0, contT=0, contB=0;
    for(int i=0; i<linha;i++){
        for(int j=0; j<coluna;j++){
            if(matriz[i][j]==1){
                contP++;
            }
            else if(matriz[i][j]==0){
                contA++;
            }
            else if(matriz[i][j]==2){
                contC++;
            }
            else if(matriz[i][j]==5){
                contRei++;
            }
            else if(matriz[i][j]==6){
                contRainha++;
            }
            else if(matriz[i][j]==4){
                contB++;
            }
            else{
                contT++;
            }
        }
    }
    printf("Quantidade de Peoes: %d\n", contP);
    printf("Quantidade de lugares sem pecas: %d\n", contA);
    printf("Quantidade de Bispos: %d\n", contB);
    printf("Quantidade de Torres: %d\n", contT);
    printf("Quantidade de Cavalos: %d\n", contC);
    printf("Quantidade de Reis: %d\n", contRei);
    printf("Quantidade de Rainhas: %d\n", contRainha);
    return 0;
}