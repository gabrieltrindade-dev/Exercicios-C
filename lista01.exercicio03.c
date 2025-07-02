#include <stdio.h>

int main(){

    float a;
    float b;
    char simbolo;
    printf("Escolha um comando: + - / * ");
    scanf(" %c", &simbolo);
    printf("Digite o primeiro valor: ");
    scanf("%f", &a);
    printf("Digite o segundo valor: ");
    scanf("%f", &b);
    float resultado;
    if(simbolo == '-'){
        resultado = a-b;
    }
    else if(simbolo == '+'){
        resultado = a+b;
    }
    else if(simbolo == '/'){
         if (b != 0) {
            resultado = a / b;
        } 
        else {
            printf("Erro: divisão por zero!\n");
            return 1;
        }
    }
    else if(simbolo=='*'){
        resultado = a*b;
    }
    else{
        printf("Operação inválida.\n");
        return 1;
    }
    printf("%.2f", resultado);
    return 0;
}