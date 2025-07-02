#include <stdio.h>
#include <stdlib.h>

int verificaSoma(int linha, int coluna, int **matriz){
    int somaLinha1=0;
    for(int j=0; j<coluna;j++){
        somaLinha1+=matriz[0][j];
    }
    for(int i=1; i<linha;i++){
        int somaResto=0;
        for(int j=0; j<coluna;j++){
            somaResto+=matriz[i][j];
        }
        if(somaResto!=somaLinha1){
            return 1;
        }
    }
    return 0;
}

int main(){
    int linha, coluna;
    printf("Digite o numero de linhas e colunas: ");
    scanf("%d %d", &linha, &coluna);
    int **matriz = malloc(linha*sizeof(int*));
    if(matriz==0){
        printf("Erro ao alocar");
        exit (1);
    }
    for(int i=0;i<linha;i++){
        matriz[i]=malloc(coluna*sizeof(int));
        if(matriz[i]==NULL){
            printf("Memoria invalida");
            exit (1);
        }
    }
    for(int i=0; i<linha;i++){
        for(int j=0; j<coluna;j++){
            printf("Valor: ");
            scanf("%d", &matriz[i][j]);
        }
    }
    int resultado = verificaSoma(linha, coluna, matriz);
    if(resultado==0){
        printf("A soma de cada uma de suas linhas totaliza o mesmo valor para todas as linhas.");
    }
    else{
        printf("A soma de cada uma de suas linhas NAO totaliza o mesmo valor para todas as linhas.");
    }
    for(int i=0;i<linha;i++){
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}