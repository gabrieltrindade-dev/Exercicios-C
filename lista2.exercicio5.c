#include <stdio.h>

int main(){

    int x,z;
    printf("Digite o valor de x: ");
    scanf("%d", &x);
    printf("Digite o valor de z: ");
    scanf("%d", &z);
    if(z<x){
        while(z<x){
            printf("Digite novamente o valor de x (ele precisa ser maior): ");
            scanf("%d", &z);
        }
    }
    int soma=0;
    int qtd=0;
    int alt=x;
    while(soma<z){
        printf("%d ", alt);
        soma+=alt;
        alt++;
        qtd++;
    }
    printf("\nDeve somar %d numeros em sequencia e o resultado e %d",qtd,soma);
    return 0;
}