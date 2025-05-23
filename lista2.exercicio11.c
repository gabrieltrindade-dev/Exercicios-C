#include <stdio.h>
#include <math.h>

int main(){
    int num;
    int num2;

    printf("digite a base: ");
    scanf("%d",&num);
    printf("digite a potencia: ");
    scanf("%d",&num2);

    double resultado =pow(num, num2);

    printf("o resultado de %d elevado a %d e %.2f\n",num,num2,resultado);

    return 0;
}