#include <stdio.h>
#include <stdlib.h>

float *acima_da_media(int n, float *vet, int *tam);

int main(){
    int n, tam=0;
    printf("Quantos elementos: ");
    scanf("%d", &n);
    float *vet = (float *)malloc(n * sizeof(float));
    if(vet==NULL){
        printf("Memoria invalida\n");
        exit (1);
    }
    for(int i=0; i<n; i++){
        printf("Valor: ");
        scanf("%f", &vet[i]);
    }
    float *resultado = acima_da_media(n, vet, &tam);
    if(resultado!=NULL){
        printf("A lista nova tem %d elementos. Lista nova:\n", tam);
        for(int i=0; i<tam; i++){
            printf("%.2f ", resultado[i]);
        }
        free (resultado);
    }
    else{
        printf("invalido");
    }
    free (vet);
    return 0;
}

float *acima_da_media(int n, float *vet, int *tam){
    float soma = 0.0; 
    for(int i=0; i<n; i++){
        soma += vet[i];
    }
    float media=soma/n;
    int cont=0;
    for(int i=0; i<n; i++){
        if(vet[i]>=media){
            cont++;
        }
    }
    float *vetN = (float *)malloc(cont * sizeof(float));
    if(vetN==NULL){
        printf("Memoria invalida\n");
        exit (1);
    }
    int j = 0;
    for(int i=0; i<n; i++){
        if(vet[i]>=media){
            vetN[j++]=vet[i];
        }
    }
    *tam = cont;
    return vetN;
}