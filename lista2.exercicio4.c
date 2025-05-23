#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int num= rand() %26;
    char sorte= 'a'+num;
    char letra;
    printf("Escolha uma letra: ");
    scanf(" %c", &letra);
    if(letra!=sorte){
        while(letra!=sorte){
            if(sorte>letra){
                printf("Chute uma letra maior: ");
            }
            else{
                printf("Chute uma letra menor: ");
            }
            scanf(" %c", &letra);
        }
        printf("Voce acertou. A letra foi %c",sorte);
    }
    else{
        printf("Parabens! Voce acertou a letra %c de primeira", sorte);
    }
    return 0;
}