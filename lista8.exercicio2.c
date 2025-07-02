#include <stdio.h>
#include <stdlib.h>

int main(){
    int linha, coluna;
    printf("Digite o numero de linhas e colunas: ");
    scanf("%d %d", &linha, &coluna);
    int **a;
    int **b;
    int **c;
    a = malloc(linha*sizeof(int*));
    if(a==NULL){
        printf("Memoria invalida");
        exit (1);
    }
    b = malloc(linha*sizeof(int*));
    if(b==NULL){
        printf("Memoria invalida");
        exit (1);
    }
    c = malloc(linha*sizeof(int*));
    if(c==NULL){
        printf("Memoria invalida");
        exit (1);
    }
    for(int i=0;i<linha;i++){
        a[i]=malloc(coluna*sizeof(int));
        if(a[i]==NULL){
            printf("Memoria invalida");
            exit (1);
        }
        b[i]=malloc(coluna*sizeof(int));
        if(b[i]==NULL){
            printf("Memoria invalida");
            exit (1);
        }
        c[i]=malloc(coluna*sizeof(int));
        if(c[i]==NULL){
            printf("Memoria invalida");
            exit (1);
        }
    }
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            printf("Valor matriz A[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
            printf("Valor matriz B[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            c[i][j]= a[i][j]+b[i][j];
        }
    }
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<linha;i++){
        free (a[i]);
        free (b[i]);
        free (c[i]);
    }
    free (a);
    free (b);
    free (c);
    return 0;
}