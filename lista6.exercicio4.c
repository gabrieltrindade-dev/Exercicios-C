#include <stdio.h>
#include <stdlib.h>

int *premiados(int n, int *inscr, float *t1, int p1,float *t2, int p2, int *tam);

int main(){
    int n, p1, p2, tam;
    printf("Quantidade de participantes: ");
    scanf("%d", &n);
    printf("Peso P1: ");
    scanf("%d", &p1);
    printf("Peso P2: ");
    scanf("%d", &p2);
    int *inscr = (int *)malloc(n * sizeof(int));
    if(inscr==NULL){
        printf("Memoria invalida");
        exit (1);
    }
    float *t1 = (float *)malloc(n * sizeof(float));
    if(t1==NULL){
        printf("Memoria invalida");
        exit (1);
    }
    float *t2 = (float *)malloc(n * sizeof(float));
    if(t2==NULL){
        printf("Memoria invalida");
        exit (1);
    }
    for(int i=0; i<n; i++){
        printf("Inscriçao: ");
        scanf("%d", &inscr[i]);
        printf("Nota 1: ");
        scanf("%f", &t1[i]);
        printf("Nota 2: ");
        scanf("%f", &t2[i]);
    }
    int *resultado = premiados(n, inscr, t1, p1, t2, p2, &tam);
    if(resultado==NULL){
        printf("Memoria invalida");
        free (resultado);
        exit (1);
    }
    else{
        printf("Vencedores: ");
        for(int i=0; i<tam; i++){
            printf("%d ", resultado[i]);
        }
    }
    free (resultado);
    free (inscr);
    free (t1);
    free (t2);
    return 0;
}

int *premiados(int n, int *inscr, float *t1, int p1,float *t2, int p2, int *tam){
    float *medias= (float *)malloc(n * sizeof(float));
    if(medias==NULL){
        printf("Memoria invalida");
        exit (1);
    }
    float maior= -1.0;
    for(int i=0; i<n; i++){
        medias[i] = ((t1[i]*p1)+(t2[i]*p2))/(p1+p2);
        if(medias[i]>maior){
            maior=medias[i];
        }
    }
    int j=0;
    *tam=0;
    for(int i=0; i<n; i++){
        if(medias[i]==maior){
            (*tam)++;
        }
    }
    int *novoVet = (int *)malloc(*tam * sizeof(int));
    if(novoVet==NULL){
        printf("Memoria invalida");
        exit (1);
    }
    j=0;
    for(int i=0; i<n; i++){
        if(medias[i]==maior){
            novoVet[j]=inscr[i];
            j++;
        }
    }
    return novoVet;
}