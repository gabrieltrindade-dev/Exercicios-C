#include <stdio.h>
#include <string.h>
#define MAX 50

int main (void) {
    char texto[MAX +2], temp ;
    int tam , i;
    gets( texto );
    tam = strlen ( texto );
    for (i = 0; i < tam ; i ++) {
    temp = texto[i];
    texto[i] = texto[ tam -1 - i ];
    texto[strlen(texto) -1 - i] = temp ;
    }
    puts ( texto );
    return 0;
}
/*eu digitei Gabriel e no final o codigo vai imprimir Gabriel,
pois no loop a string na poiscao i recebe tam-1-1, mas
logo depois, ainda no loop os caracteres invertem de novo
mudando em nada oque foi digitado*/