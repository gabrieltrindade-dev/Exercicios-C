#include <stdio.h>
#include <stdlib.h>

int *aprovados(int n, int *mat, float *notas, int *tam);

int main(){
    int n, tam;
    printf("Quantidade de alunos: ");
    scanf("%d", &n);
    int *mat = (int *)malloc(n * sizeof(int));
    if(mat==NULL){
        printf("Memoria invalida");
        exit (1);
    }
    float *notas = (float *)malloc(n * sizeof(float));
    if(notas==NULL){
        printf("Memoria invalida");
        exit (1);
    }
    int *resultado = aprovados(n, mat, notas, &tam);
    if(resultado==NULL){
        printf("Memoria invalida");
        exit (1);
    }
    else{
        for(int i=0; i<tam; i++){
            printf("Matricula: %d ", resultado[i]);
        }
        free (resultado);
    }
    free (mat);
    free (notas);
    return 0;
}

int *aprovados(int n, int *mat, float *notas, int *tam){
    *tam = 0;
    for(int i=0; i<n; i++){
        printf("Matricula: ");
        scanf("%d", &mat[i]);
    }
    for(int i=0; i<n; i++){
        printf("Notas: ");
        scanf("%f", &notas[i]);
        if(notas[i]>=5){
            (*tam)++;;
        }
    }
    int *novoVet = (int *)malloc(*tam * sizeof(int));
    if(novoVet==NULL){
        printf("Memoria invalida");
        exit (1);
    }
    int j=0;
    for(int i =0; i<n; i++){
        if(notas[i]>=5){
            novoVet[j] = mat[i];
            j++;
        }
    }
    return novoVet;
}