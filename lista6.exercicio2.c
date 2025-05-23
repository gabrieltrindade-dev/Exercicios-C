#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

char *compactar(char *s);

int main(){
    char s[max];
    printf("Digite uma frase: ");
    fgets(s, sizeof(s), stdin);
    char *resultado= compactar(s);
    printf("%s", resultado);
    free (resultado);
    return 0;
}

char *compactar(char *s){
    int inicio = 0, fim = strlen(s)-1;
    while(s[inicio]==' '){
        inicio++;
    }
    while(s[fim]==' '){
        fim--;
    }
    int tam = fim-inicio+1;
    char *novoS = (char *)malloc(tam * sizeof(char));
    if(novoS==NULL){
        printf("Memoria invalida");
        exit (1);
    }
    for (int i = 0; i < tam; i++) {
        novoS[i] = s[inicio + i];
    }
    novoS[tam]='\0';
    return novoS;
}