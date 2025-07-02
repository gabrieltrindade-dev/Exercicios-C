#include <stdio.h>
#include <stdlib.h>

int**multiplicar_matriz(int linhas,int colunas,int **matriz1,int**matriz2){
    int**mult=(int**)malloc(linhas*sizeof(int*));
    if (mult==NULL){
        printf("memoria insuficiente\n");
        exit(1);
    }
    for (int i=0;i<linhas;i++){
        mult[i]=(int*)malloc(colunas*sizeof(int));
        if (mult[i]==NULL){
            printf("memoria insuficiente\n");
            exit(1);
        }
    }
    for (int i=0;i<linhas;i++){
        for (int j=0;j<colunas;j++){
            mult[i][j]=matriz1[i][j]*matriz2[i][j];
        }
    }
    return mult;
}

int main(){
    int linhas,colunas;
    printf("digite o numero de linhas nas 2 matrizes\n");
    scanf("%d",&linhas);
    printf("digite o numero de colunas nas 2 matrizes\n");
    scanf("%d",&colunas);

    int**matriz1=(int**)malloc(linhas*sizeof(int*));
    int**matriz2=(int**)malloc(linhas*sizeof(int*));
    if (matriz1==NULL||matriz2==NULL){
        printf("memoria insuficiente\n");
        exit(1);
    }

    for (int i=0;i<linhas;i++){
        matriz1[i]=(int*)malloc(colunas*sizeof(int));
        matriz2[i]=(int*)malloc(colunas*sizeof(int));
        if (matriz1[i]==NULL||matriz2[i]==NULL){
            printf("memoria insuficiente\n");
            exit(1);
        }
    }

    for (int i=0;i<linhas;i++){
        for (int j=0;j<colunas;j++){
            printf("digite um numero na matriz1\n");
            scanf("%d",&matriz1[i][j]);
        }
    }
    for (int i=0;i<linhas;i++){
        for (int j=0;j<colunas;j++){
            printf("digite um numero na matriz2\n");
            scanf("%d",&matriz2[i][j]);
        }
    }

    int**mult=multiplicar_matriz(linhas,colunas,matriz1,matriz2);
    printf("a multiplicacao das matrizes :\n");
    for (int i=0;i<linhas;i++){
        for (int j=0;j<colunas;j++){
            printf("%d ",mult[i][j]);
        }
        printf("\n");
    }

    for (int i=0;i<linhas;i++){
        free(matriz1[i]);
        free(matriz2[i]);
        free(mult[i]);
    }
    free(mult);
    free(matriz1);
    free(matriz2);
    return 0;
}
