#include <stdio.h>

int main() {
    int n;
    int i = 1;
    int soma = 0;
    int cont = 0;
    printf("Escolha a quantidade de numeros que devem ser somados: ");
    scanf("%d", &n);
    while(cont<n){
        soma+=i;
        i+=2;
        cont++;
    }
    printf("%d",soma);
    return 0;
}