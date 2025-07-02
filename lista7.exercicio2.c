#include <stdio.h>
#include <string.h>

int main (void) {
    char *frase = "Otimo teste";
    char *p , misterio[80];
    int i = 0;
    int j = 0;
    p = frase + strlen (frase) - 1;
    while (*p != ' ') { //misterio ira receber: e t s e t
        misterio[i] = *p;
        i ++; p --;
    }
    misterio[i] = ' '; i ++;    //misterio, que ja tem etset ira receber: ' '
    while ( frase[j] != ' ') { //misterio, que ja tem etset ,ira receber: O t i m o
        misterio [i] = frase[j];
        j ++; i ++;
    } 
    misterio[i] = '\0';
    puts (misterio); //Será impresso: etset Otimo
    return 0;
}