#include <stdio.h>

float calculador(float a,float b, float c){
    float resultado = (a+b+c)/3;
    return resultado;
}

int main(){
    float p1, p2, p3, media;
    printf("Nota da p1: ");
    scanf("%f", &p1);
    while(p1<0 || p1>10){
        printf("Digite novamente a nota da p1: (0 a 10) ");
        scanf("%f", &p1);
    }
    printf("Nota da p2: ");
    scanf("%f", &p2);
    while(p2<0 || p2>10){
        printf("Digite novamente a nota da p2: (0 a 10) ");
        scanf("%f", &p2);
    }
    printf("Nota da p3: ");
    scanf("%f", &p3);
    while(p3<0 || p3>10){
        printf("Digite novamente a nota da p3: (0 a 10) ");
        scanf("%f", &p3);
    }
    media = calculador(p1, p2, p3);
    printf("Sua media ficou %.2f. Logo, ",media);
    if(media>=6){
        printf("Aprovado");
    }
    else if(media>=4 && media<6){
        printf("VS");
    }
    else{
        printf("Reprovado");
    }
    return 0;
}