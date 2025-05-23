#include <stdio.h>

unsigned int inverte(unsigned int x){
    unsigned int xInverso = 0;
    while(x>0){
        xInverso = xInverso*10 + x%10;
        x/=10;
    }
    return xInverso;
}

int main(){
    unsigned int num;
    unsigned int novoNum;
    printf("Digite um numero: ");
    scanf("%u", &num);
    novoNum = inverte(num);
    printf("Novo numero: %u", novoNum);
    return 0;
}