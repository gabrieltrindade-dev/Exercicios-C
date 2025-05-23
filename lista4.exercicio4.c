#include <stdio.h>
#define max 100

int testa_PA(int n, int* v);

int main(){
    int n;
    printf("Quantidade de valores: ");
    scanf("%d", &n);
    if(n<3 || n>100){
        printf("Vetor nao suficiente para gerar PA");
    }
    else{
        int v[max];
        int result = testa_PA(n,v);
        if(result==0){
            printf("Nao eh PA");
        }
        else{
            printf("Eh uma PA e a razao eh %d", result);
        }
    }
    return 0;
}

int testa_PA(int n, int* v){
    for(int i=0; i<n; i++){
        printf("Valor: ");
        scanf("%d", &v[i]);
    }
    int k= v[1]-v[0];
    int cont=0;
    for(int i=0; i<n; i++){
        if(v[i]==v[0]+k*i){
            cont++;
        }
    }
    if(cont==n){
        return k;
    }
    else{
        return 0;
    }
}