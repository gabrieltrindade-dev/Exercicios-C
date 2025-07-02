#include <stdio.h>
#include <stdlib.h>

struct elemento {
    float info;
    struct elemento *prox;
};
typedef struct elemento Elemento;

Elemento* filtra(Elemento *lst, float min, float max) {
    Elemento *ant = NULL;
    Elemento *p = lst;
    while (p != NULL) {
        Elemento *prox = p->prox;
        if (p->info < min || p->info > max) {
            if (ant == NULL) {
                lst = prox;
            } else {
                ant->prox = prox;
            }
            free(p);
        } else {
            ant = p;
        }
        p = prox;
    }
    return lst;
}
