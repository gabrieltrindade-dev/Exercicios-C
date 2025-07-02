#include <stdio.h>

void impressao(int *vet, int n){
    printf("Vetor: ");
    for(int i=0; i<n; i++){
        printf("%d ", vet[i]);
    }
}

void inicializacao(int *vet, int n){
    for(int i=0; i<n; i++){
        vet[i]= (i+1)*5;
    }
}

int main (void){
    int n = 10;
    int vet[n];
    inicializacao(vet, n);
    impressao(vet, n);
    return 0;
}