#include <stdio.h>
#define MAX 100

float media(int n, float *v);

int main(){
    int n;
    float v[MAX];
    printf("digite o numero de elementos em v: ");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        printf("digite um elemento em v: ");
        scanf("%f",&v[i]);
    }
    float resultado=media(n,v);
    printf("o resultado eh %.2f",resultado);
    return 0;
}

float media(int n, float *v){
    float m=0;
    for (int i=0;i<n;i++){
        m=m+v[i];
    }
    m=m/n;
    return m;
}