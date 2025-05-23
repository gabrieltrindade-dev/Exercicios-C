#include <stdio.h>

int main(){
    int horas;
    float valor;
    float salario;

    printf("digite suas horas trabalhadas: ");
    scanf(" %d",&horas);
    printf("digite o valor da hora: ");
    scanf(" %f",&valor);

    if(horas<=40){
        salario=horas*valor;
    }
    else if(horas<=60){
        salario = 40 * valor + (horas - 40) * valor * 1.5;
    }
    else{
        salario = 40 * valor + 20 * valor * 1.5 + (horas - 60) * valor * 2;
    }
    printf("seu salario semanal e %.2f",salario);

    return 0;
}