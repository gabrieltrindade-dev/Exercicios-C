#include <stdio.h>
#define max 100
int maiores(int n, int * vet, int x);

int main(){
    int n;
    int x;
    int qntmaior;
    int num;
    printf("digite o valor de n: ");
    scanf("%d",&n);
    int vet[100];
    for (int i =0;i<n;i++){
        printf("\ndigite um valor pro vetor: ");
        scanf("%d",&num);
        vet[i]=num;
    }
    printf("digite o valor de x: ");
    scanf("%d",&x);
    qntmaior=maiores(n,vet,x);
    printf("Ha %d numeros maiores que x no vetor",qntmaior);
    return 0;
}

int maiores(int n, int * vet, int x){
    int qnt=0;
    for (int i = 0;i<n;i++){
        if (vet[i]>x){
            qnt++;
        }
    }
    return qnt;
}