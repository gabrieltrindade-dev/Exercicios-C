#include <stdio.h>

int main(){

    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);
    if (num <= 1) {
        printf("NUMERO NAO PRIMO\n");
        return 0;
    }
    int contDiv = 0;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            contDiv++;
            break;
        }
    }

    if (contDiv == 0) {
        printf("NUMERO PRIMO\n");
    } else {
        printf("NUMERO NAO PRIMO\n");
    }
    return 0;
}