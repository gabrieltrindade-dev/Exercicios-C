#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char n;
    char string[20];
    printf("digite uma string\n");
    scanf(" %[^\n]",string);

    printf("digite uma letra n\n");
    scanf(" %c",&n);

    char *p = strchr(string, n);
    char *u = strrchr(string, n);

    if (p != NULL) {
        printf("A primeira ocorrencia da letra '%c' comeca em: %s\n", n, p);
    } else {
        printf("A letra '%c' nao foi encontrada na string.\n", n);
    }
    if (u!=NULL&&u!=p){
        printf("a ultima ocorrencia e %s\n",u);
    }
    size_t q = strspn(string, "abcdefghijklmnopqrstuvwxyz");
    printf("A string comeca com %zu letra(s) minuscula(s) consecutiva(s)\n", q);

    return 0;
}