#define MAX 4
#define MAXNOME 31
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void atribui(char **nomes, int indice, char *nome);
char * get_sobrenome(char *nome);
void main()
{
int i;
char **nomes;
char *sobrenome;
nomes = (char **) malloc(MAX*sizeof(char *));
for ( i=0 ; i<MAX ; i++) {
nomes[i] = (char *) malloc(sizeof(char)*MAXNOME);
}
atribui(nomes,0,"Fulano Silva"); atribui(nomes,1,"Maria do Carmo");
atribui(nomes,2,"Beltrano Belmonte"); atribui(nomes,3,"Pedro dos Santos");
for (i=0 ; i<MAX ; i++) {
sobrenome = get_sobrenome(nomes[i]);
printf("\n%s ", sobrenome);
printf(" %d",strlen(sobrenome)>5?i:0);
}

printf("\n%c", nomes[0][3]); // 3o printf vai imprimir a
}

void atribui(char **nomes, int indice, char *nome){
strcpy(nomes[indice],nome);
}

char * get_sobrenome(char *nome){
char *ultimoEspaco = NULL;

for (int i = 0; nome[i] != '\0'; i++) {
    if (nome[i] == ' ') {
        ultimoEspaco = &nome[i];
    }
}

if (ultimoEspaco != NULL) {
    return ultimoEspaco + 1;
}

return nome;
}