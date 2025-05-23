#include <stdio.h>

void defineVetor(int *v){
    for(int i=0; i<7; i++){
        printf("Digite o valor: ");
        scanf("%d", &v[i]);
    }
}

int listaEPesquisa(int *v){
    for(int i=0; i<7; i++){
        printf("Valor: %d Posicao: %d\n", v[i],i);
    }
    int num;
    int guard = -1;
    printf("Escolha um numero: ");
    scanf("%d", &num);
    for(int i=0; i<7;i++){
        if(num==v[i]){
            guard = i;
            break;
        }
    }
    return guard;
}

void novoVetor(int *v, int *vN){
    vN[0]=v[0];
    for(int j=1; j<7; j++){
        vN[j]=(v[j]+vN[j-1]);
    }
}

int main(){
    int vetor[7];
    defineVetor(vetor);
    int result = listaEPesquisa(vetor);
    if(result==-1){
        printf("O valor nao esta presente no vetor\n");
    }
    else{
        printf("Sua posicao eh %d\n", result);
    }
    int vetN[7];
    novoVetor(vetor, vetN);
    for(int i=0;i<7;i++){
        printf("%d\n", vetN[i]);
    }
    return 0;
}