#include <stdio.h>
#include <stdlib.h>

int descobrirSimetria(int linha, int coluna, int **matriz){
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            if(matriz[i][j]!=matriz[j][i]){
                return 1;
            }
        }
    }
    return 0;
}

int alocacao(int linha, int coluna, int ***matriz){
    *matriz = malloc(linha*sizeof(int*));
    if(*matriz==NULL){
        printf("Memoria invalida");
        exit (1);
    }
    for(int i=0;i<linha;i++){
        (*matriz)[i] = malloc(coluna*sizeof(int));
        if((*matriz)[i]==NULL){
            printf("Memoria invalida");
            exit (1);
        }
    }
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            printf("Valor matriz[%d][%d]: ", i,j);
            scanf("%d", &(*matriz)[i][j]);
        }
    }
}

int main(){
    int linha, coluna;
    printf("Digite o numero de linhas e de colunas: ");
    scanf("%d %d", &linha,&coluna);
    int **matriz;
    alocacao(linha, coluna, &matriz);
    int resultado = descobrirSimetria(linha, coluna, matriz);
    if(resultado==0){
        printf("A matriz eh simetrica");
    }
    else{
        printf("A matriz nao eh simetrica");
    }
    for(int i=0;i<linha;i++){
        free (matriz[i]);
    }
    free (matriz);
    return 0;
}