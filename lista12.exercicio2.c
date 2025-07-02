#include <stdio.h>
#include <stdlib.h>

int soma_impares(int vetor[], int tamanho){
    if (tamanho == 0) return 0;
    int atual = vetor[tamanho - 1];
    if (atual % 2 != 0){
        return atual + soma_impares(vetor, tamanho - 1);
    }
    else{
        return soma_impares(vetor, tamanho - 1);
    }
}

int main(){
    int n;
    printf("Digite a quantidade de elementos: ");
    scanf("%d", &n);
    int *vetor = (int *)malloc(n * sizeof(int));
    if(vetor==NULL){
        printf("Memoria invalida");
        exit (1);
    }
    for(int i=0; i<n; i++){
        printf("Valor: ");
        scanf("%d", &vetor[i]);
    }
    printf("Resultado: %d", soma_impares(vetor, n));
    free (vetor);
    return 0;
}