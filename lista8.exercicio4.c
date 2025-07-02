#include <stdio.h>
#include <string.h>
#include <math.h>
#define tam 100

int main(){
    int linha=tam, coluna=tam;
    char matriz[linha][coluna];
    int cont=0, i=0;
    while(1){
        char nome[tam];
        printf("Digite um nome ou 'fim' para encerrar: ");
        scanf(" %[^\n]", nome);
        if(strcmp(nome,"fim")==0){
            break;
        }
        strcpy(matriz[i],nome);
        cont += strlen(nome);
        i++;
    }
    float media = (float)cont/i;
    double variancia = 0;
    for (int j = 0; j < i; j++) {
        double diferenca = (double)strlen(matriz[j]) - (double)media;
        variancia += pow(diferenca, 2);
    }
    variancia /= i;
    printf("A media eh %f\n", media);
    printf("A variancia eh %.2f", variancia);
    return 0;
}