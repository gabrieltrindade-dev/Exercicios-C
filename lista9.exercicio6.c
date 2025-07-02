#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa {
int codigo;
char nome[81];
};
typedef struct pessoa Pessoa;

Pessoa* busca(int n, Pessoa** vet, int codigo);

int main(){
int n;
printf("digite o tamanho do vetor\n");
scanf("%d",&n);
Pessoa**vetor=(Pessoa**)malloc(n*sizeof(Pessoa*));
if(vetor==NULL){
    printf("memoria insuficiente\n");
    exit(1);
}
for (int i=0;i<n;i++)
{
    vetor[i]=(Pessoa*)malloc(sizeof(Pessoa));
    if(vetor[i]==NULL){
        printf("memoria insuficiente\n");
        exit(1);
}
    printf("Digite o código da pessoa %d: ", i + 1);
    scanf("%d", &vetor[i]->codigo);
    printf("Digite o nome da pessoa %d: ", i + 1);
    scanf(" %[^\n]", vetor[i]->nome);
}

int codigoBusca;
printf("Digite o código que deseja buscar: ");
scanf("%d", &codigoBusca);

Pessoa*resultado =busca(n,vetor,codigoBusca);
if(resultado!=NULL){
    printf("pessoa encontrada %s codigo %d",resultado->nome,resultado->codigo);
}
else{
    printf("pessoa nao encontrada");
}

for (int i=0;i<n;i++){
    free(vetor[i]);
}
free(vetor);

return 0;
}

Pessoa* busca(int n, Pessoa** vet, int codigo){
int ini=0;
int fim=n-1;
int meio;
do{
    meio=(ini+fim)/2;
    if(codigo>vet[meio]->codigo){
        ini=meio+1;
    }
    else if(codigo<vet[meio]->codigo){
        fim=meio-1;
    }
}while(codigo!=vet[meio]->codigo && ini<=fim);
if(codigo==vet[meio]->codigo){
    return vet[meio];
}
else {
    return NULL;
}
}