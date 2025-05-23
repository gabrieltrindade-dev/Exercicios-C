#include <stdio.h>
#define max 20

void defineV(int *v1, int *v2, char *v3){
    for(int i=0; i<max; i++){
        printf("Valor lista 1: ");
        scanf("%d", &v1[i]);
        printf("Valor lista 2: ");
        scanf("%d", &v2[i]);
        printf("Escolha x,+,-,/ : ");
        scanf(" %c", &v3[i]);
    }
}

void conversao(int *v1, int *v2, char *v3, float *v4){
    for(int i=0; i<max; i++){
        if(v3[i]=='+'){
            v4[i] = v1[i] + v2[i];
        }
        else if(v3[i]=='-'){
            v4[i] = v1[i] - v2[i];
        }
        else if(v3[i]=='/'){
            if (v2[i] == 0) {
                printf("Erro!!! Divisao por zero na posição %d\n", i);
                v4[i] = 0.0;  
            } 
            else {
                v4[i] = (float)v1[i] / v2[i];
            }   
        }
        else{
            v4[i] = v1[i] * v2[i];
        }
    }
}

int main(){
    int vet1[max], vet2[max];
    char vet3[max];
    float  vet4[max];
    defineV(vet1, vet2, vet3);
    conversao(vet1, vet2, vet3, vet4);
    for(int i=0; i<max; i++){
        printf("%d %c %d = %.2f\n", vet1[i], vet3[i], vet2[i], vet4[i]);
    }
    return 0;
}