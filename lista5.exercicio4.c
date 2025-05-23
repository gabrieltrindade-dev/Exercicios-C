#include <stdio.h>
#include <stdlib.h>

int main(){
    char*string=(char*)malloc(100*sizeof(char));
    if (string==NULL){
        printf("memoria insuficiente\n");
        exit(1);
    }
    printf("digite um string: ");
    scanf(" %s",string);

    char primeira=string[0];
    int tamanho=0;
    int i;
    for (i=0;string[i]!='\0';i++){
        tamanho++;
    }
    i--;
    char ultimo = string[i];

    printf("primeiro caracter %c\n",primeira);
    printf("ultimo caracter %c\n",ultimo);
    printf("o tamanho=%d\n",tamanho);
    free(string);
    return 0;
}