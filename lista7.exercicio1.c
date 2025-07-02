#include <stdio.h>

void f1 ( int v) {
    v = v + 1;
    printf (" f1 = %d\n " , v); //Imprime: f1 = 2
}

void f2 ( int *v) {
    *v = *v + 1;
    printf (" f2 = %d\n " , *v); //Imprime: f2 = 2
}

int f3 ( int v) {
    v = v + 1;
    printf (" f3 = %d\n " , v); //Imprime: f3 = 3
    return v;
}

int main (void) {
    int v = 1;
    f1 (v);
    f2 (&v );
    v = f3 (v);
    printf (" main = %d \n" , v); //Imprime: main = 3
    /*ou seja, sera impresso: 
    f1 = 2
    f2 = 2
    f3 = 3
    main = 3 
    */
}