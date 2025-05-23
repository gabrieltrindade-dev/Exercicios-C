#include <stdio.h>
#include <math.h>

float transformador(float a, float b, float c){
    float r1= (-b+sqrt((b*b)-4*a*c))/(2*a);
    return r1;
}

float transformador2(float a, float b, float c){
    float r2= (-b-sqrt((b*b)-4*a*c))/(2*a);
    return r2;
}

int main(){
    float a,b,c;
    float x1,x2;
    printf("A: ");
    scanf("%f", &a);
    printf("B: ");
    scanf("%f", &b);
    printf("C: ");
    scanf("%f", &c);
    if (a == 0) {
        printf("Nao eh equaçao do segundo grau\n");
        return 1;
    }
    float delta = b * b - 4 * a * c;
    if (delta < 0) {
        printf("Nao existem raizes reais\n");
    } 
    else if (delta == 0) {
        x1 = transformador(a, b, c);
        printf("Raiz unica: x = %.2f\n", x1);
    } 
    else {
        x1 = transformador(a, b, c);
        x2 = transformador2(a,b,c);
        printf("X1: %.2f X2: %.2f", x1, x2);
    }
    return 0;
}