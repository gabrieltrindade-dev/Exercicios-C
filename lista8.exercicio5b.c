#include <stdio.h>
#include <stdlib.h>

void soma_diag_princ(int linhas,int colunas,int**matriz1,int**matriz2,int*soma1,int*soma2){
    for (int i=0;i<linhas;i++){
        for (int j=0;j<colunas;j++){
            if (i==j){
                *soma1+=matriz1[i][j];
                *soma2+=matriz2[i][j];
            }
        }
    }
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

    int soma_diag_1=0,soma_diag_2=0;
    soma_diag_princ(linhas,colunas,matriz1,matriz2,&soma_diag_1,&soma_diag_2);
    printf("diagonal principal da matriz 1: %d\n",soma_diag_1);
    printf("diagonal principal da matriz 2: %d\n",soma_diag_2);

    for (int i=0;i<linhas;i++){
        free(matriz1[i]);
        free(matriz2[i]);
    }
    free(matriz1);
    free(matriz2);
    return 0;
}
