#include <stdio.h>

void calcula_corrida(float dist, float *b1, float *b2);

int main(){
    float dist;
    printf("Digite a distancia: ");
    scanf("%f", &dist);
    float band1, band2;
    calcula_corrida(dist, &band1, &band2);
    printf("Valor da corrida na bandeira 1: %.2f\n", band1);
    printf("Valor da corrida na bandeira 2: %.2f", band2);
    return 0;
}

void calcula_corrida(float dist, float *b1, float *b2){
    *b1 = 4.95+(dist*2.5);
    *b2 = 4.95+(dist*3.0);
}