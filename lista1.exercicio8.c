#include <stdio.h>

int total_de_notas(int valor);

int main(){

    int valor;
    printf("Escreva o valor: ");
    scanf("%d", &valor);
    int resultado = total_de_notas(valor);
    printf("Foram utilizadas %d cedulas", resultado);
    return 0;
}

int total_de_notas(int valor){
    int notas = 0;
    int total = valor;
    while(total>=100){
        total-=100;
        notas+=1;
    }
    while(total>=50){
        total-=50;
        notas+=1;
    }
    while(total>=20){
        total-=20;
        notas+=1;
    }
    while(total>=10){
        total-=10;
        notas+=1;
    }
    while(total>=5){
        total-=5;
        notas+=1;
    }
    while(total>=2){
        total-=2;
        notas+=1;
    }
    while(total>=1){
        total-=1;
        notas+=1;
    }
    return notas;
}