#include <stdio.h>

int main() {

    int a;
    int b;
    int c;
    int maior;
    int menor;
    float media;
    printf("Digite o primeiro valor: ");
    scanf("%d", &a);
    printf("Digite o segundo valor: ");
    scanf("%d", &b);
    printf("Digite o terceiro valor: ");
    scanf("%d", &c);
    if(a>=b && a>=c){
        maior = a;
    }
    else if(b>=a && b>=c){
        maior = b;
    }
    else{
        maior = c;
    }
    if(a<=b && a<=c){
        menor = a;
    }
    else if(b<=a && b<=c){
        menor = b;
    }
    else{
        menor = c;
    }
    media = ((float) a+(float) b+ (float) c)/3;
    printf("Maior: %d Menor: %d Media: %f \n", maior, menor, media);
    if(a%2==0){
        printf("%d eh par\n",a);
    }
    if(b%2==0){
        printf("%d eh par\n",b);
    }
    if(c%2==0){
        printf("%d eh par\n",c);
    }
    return 0;
}