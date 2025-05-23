#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* cifra_cesar(char* msg);

int main(){
    char msg[100];
    printf("digite a mensagem\n");
    scanf("%[^\n]",msg);
    char*resultado=cifra_cesar(msg);

    printf("%s",resultado);

    free(resultado);
    return 0;
    }

    char* cifra_cesar(char* msg){
    int len=strlen(msg);
    char*resultado=(char*)malloc((len+1)*sizeof(char));
    if (resultado==NULL){
        printf("memoria insuficiente\n");
        exit(1);
    }
    for (int i = 0; i < len; i++) {
        char c = msg[i];

        if (c >= 'a' && c <= 'z') {
            resultado[i] = ((c - 'a' + 3) % 26) + 'a';
        }
        else if (c >= 'A' && c <= 'Z') {
            resultado[i] = ((c - 'A' + 3) % 26) + 'A';
        }
        else {
            resultado[i] = c;
        }
    }

    resultado[len]='\0';
    return resultado;
}