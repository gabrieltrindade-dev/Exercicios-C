#include <stdio.h>
#define MAX 100

float variancia(int n,float soma_altura,float*v){
    float media=soma_altura/n;
    float resultado=0;
    for (int i=0;i<n;i++){
        resultado+=(v[i]-media)*(v[i]-media);
    }
    return resultado/(n-1);
}
int main(){
    int n;
    printf("digite o numero de pessoas: ");
    scanf(" %d",&n);

    char sexo;
    float altura;
    int idade;

    int mulheres=0;
    int homens=0;

    float soma_altura=0;
    float v[MAX];
    for (int i=0;i<n;i++){
        printf("digite o sexo: ");
        scanf(" %c",&sexo);

        printf("digite o altura: ");
        scanf(" %f",&altura);
        soma_altura+=altura;
        v[i]=altura;

        printf("digite o idade: ");
        scanf(" %d",&idade);
        if(sexo=='m'&&idade>=20&&idade<=35){
            mulheres+=1;
        }
        else if(sexo=='h'&&altura>1.80){
            homens+=1;
        }
    }
    float resultado=variancia(n,soma_altura,v);


    printf("ha %d mulheres entre 20 e 35 anos\n",mulheres);
    printf("ha %d homens com mais de 1,80 de altura\n",homens);
    printf("a variancia da altura e %.2f",resultado);
    return 0;
}