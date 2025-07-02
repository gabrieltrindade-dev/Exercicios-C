#include <stdlib.h>
#include <stdio.h>
struct elemento {
int info; /* Valor inteiro armazenado */
struct elemento *prox; /* Ponteiro para o próximo elemento */
};
typedef struct elemento Elemento;

Elemento* copia(Elemento* lst){
if(lst==NULL){
    return NULL;
}
Elemento*nova_lista=NULL;
Elemento*ultimo=NULL;
Elemento*p=lst;
while(p!=NULL){
    Elemento*nova=(Elemento*)malloc(sizeof(Elemento));
    if (nova==NULL){
        printf("memoria insuficiente\n");
        exit(1);
    }
    nova->info = p->info;
    nova->prox=NULL;
    if(nova_lista==NULL){
        nova_lista=nova;
    }
    else{
        ultimo->prox=nova;
    }
    ultimo=nova;
    p=p->prox;

}



return nova_lista;
}