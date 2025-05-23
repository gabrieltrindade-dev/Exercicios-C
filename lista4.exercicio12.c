#include <stdio.h>
#include <string.h>
#define max 21

int main(){
    char frase[max];
    printf("Digite uma frase: ");
    fgets(frase, max, stdin);
    if (frase[strlen(frase) - 1] == '\n') {
        frase[strlen(frase) - 1] = '\0';
    }
    char caracter;
    printf("Caracter a remover: ");
    caracter = getchar();
    char fraseNova[max];
    int j=0;
    for(int i=0; i<strlen(frase); i++){
        if(frase[i]!=caracter){
            fraseNova[j]=frase[i];
            j++;
        }
    }
    fraseNova[j]='\0';
    printf("Frase nova: %s", fraseNova);
    return 0;
}