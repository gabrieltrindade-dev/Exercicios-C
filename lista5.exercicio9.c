#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char*nome=(char*)malloc(100*sizeof(char));
    char*endereco=(char*)malloc(100*sizeof(char));
    char*telefone=(char*)malloc(100*sizeof(char));
    char*resultado=(char*)malloc(300*sizeof(char));
    if (nome==NULL||endereco==NULL||telefone==NULL||resultado==NULL){
        printf("memoria insuficiente\n");
        exit(1);
    }
    printf("digite seu nome\n");
    scanf(" %99[^\n]",nome);
    printf("digite seu endereco\n");
    scanf(" %99[^\n]",endereco);
    printf("digite seu telefone\n");
    scanf(" %99[^\n]",telefone);

    strcpy(resultado,"Nome: ");
    strcat(resultado,nome);
    strcat(resultado," Endereco: ");
    strcat(resultado,endereco);
    strcat(resultado," Telefone: ");
    strcat(resultado,telefone);

    printf("%s\n",resultado);
    free(nome);
    free(telefone);
    free(endereco);
    return 0;
}