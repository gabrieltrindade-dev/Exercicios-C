#include <conio.h>
#include <stdio.h>

void main(){
    float vet[5] = {1.1,2.2,3.3,4.4,5.5};
    float *f;
    int i;
    f = vet;
    printf("contador/valor/valor/endereco/endereco");
    for(i = 0 ; i <= 4 ; i++){
    printf("\ni = %d",i);
    printf(" vet[%d] = %.1f",i, vet[i]);
    printf(" *(f + %d) = %.1f",i, *(f+i));
    printf(" &vet[%d] = %X",i, &vet[i]);
    printf(" (f + %d) = %X",i, f+i);
    }
}
/*
contador/valor/valor/endereco/endereco
i=0 vet[0]=1.1 *(f + 0) = 1.1 &vet[0] = endereco de memoria vet [0] (f + 0) = endereço de memoria vet[0]
i=1 vet[1]=2.2 *(f + 1) = 2.2 &vet[1] = endereco de memoria vet [1] (f + 1) = endereço de memoria vet[1]
i=2 vet[2]=3.3 *(f + 2) = 3.3 &vet[2] = endereco de memoria vet [2] (f + 2) = endereço de memoria vet[2]
i=3 vet[3]=4.4 *(f + 3) = 4.4 &vet[3] = endereco de memoria vet [3] (f + 3) = endereço de memoria vet[3]
i=4 vet[4]=5.5 *(f + 4) = 5.5 &vet[4] = endereco de memoria vet [4] (f + 4) = endereço de memoria vet[4]
*/