#include <stdio.h>
#include <stdlib.h>
#define max 80

char *transformador(char *vet){
    int n=0;
    for(int i=0; vet[i]!='\0';i++){
        if(vet[i]!=' '){
            n++;
        }
    }
    char *novoVet = (char *)malloc((n+1) * sizeof(char));
    if(novoVet==NULL){
        printf("Memoria invalida");
        exit (1);
    }
    int k=0;
    int j=0;
    for(int i = 0; vet[i] != '\0'; i++){
        if(vet[i] != ' '){
            char letra = vet[i];
            if(letra >= 'a' && letra <= 'z'){
                letra = letra - ('a' - 'A');
            }
            j++;
            novoVet[k] = ((letra - 'A' + j) % 26) + 'A';
            k++;
            if(j == 5){
                j = 0;
            }
        }
    }
    novoVet[k] = '\0';
    return novoVet;
}

int main (){
    char vet[80];
    scanf(" %[^\n]", vet);
    char *resultado = transformador(vet);
    printf("\n%s", resultado);
    free (resultado);
    return 0;
}