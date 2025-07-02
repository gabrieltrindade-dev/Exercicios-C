#include <stdio.h>

void impressao(char *vet, int n){
    printf("Vetor: ");
    for(int i=0; i<n; i++){
        printf("%c ", vet[i]);
    }
}

void inicializacao(char *vet, int n){
    for(int i=0; i<n; i++){
        vet[i]= 'a'+i;
    }
}

int main (){
    int n = 26;
    char vet[n];
    inicializacao(vet , n);
    impressao(vet, n);
    return 0;
}