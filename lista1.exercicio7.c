#include <stdio.h>
#include <math.h>

int main(){
    float num;
    printf("Escolha um numero: ");
    scanf("%f", &num);
    float cima = ceil(num);
    float baixo = floor(num);
    printf("Arredondado para cima: %.1f \n", cima);
    printf("Arredondado para baixo: %.1f", baixo);
    return 0;
}