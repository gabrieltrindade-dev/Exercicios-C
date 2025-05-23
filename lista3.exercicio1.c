#include <stdio.h>
#define pi 3.14159265

void calc_circulo(float r, float *circunferencia, float *area);

int main(){
    float r;
    float circunferencia;
    float area;


    printf("digite o raio da circunferencia: ");
    scanf("%f",&r);
    calc_circulo(r, &circunferencia, &area);

    printf("area = %.2f, circunferencia= %.2f" ,area,circunferencia);

    return 0;
}

void calc_circulo(float r, float * circunferencia, float * area){
    *circunferencia=2*r*pi;
    *area=pi*r*r;
}