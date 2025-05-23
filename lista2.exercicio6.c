#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int numAleat = rand()%101;
    int num;
    printf("Tente acertar o numero: ");
    scanf("%d", &num);
    int qtd=1;
    if(num!=numAleat){
        while(num!=numAleat){
            if(numAleat>num){
                printf("Chute mais alto\n");
            }
            else{
                printf("Chute mais baixo\n");
            }
            qtd++;
            scanf("%d", &num);
        }
        printf("Voce acertou. O numero sorteado foi %d. Foram %d repeticoes",numAleat, qtd);
    }
    else{
        printf("Parabens! Voce acertou de primeira");
    }
    return 0;
}