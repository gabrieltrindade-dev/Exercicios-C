#include <stdio.h>

int main(){

    int segundos;
    printf("Escolha um numero:");
    scanf("%d", &segundos);
    int horas = segundos/3600;
    segundos %= 3600;
    int minutos =  segundos/60;
    segundos %= 60;
    printf("Horas: %d Minutos: %d Segundos: %d", horas, minutos, segundos);
    return 0;
}
