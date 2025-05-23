#include <stdio.h>

int main(){
    for(int i=1000; i<=9999; i++){
        int doisP = i/100;
        int doisU = i%100;
        int soma = doisP+doisU;
        if((soma*soma)==i){
            printf("O numero %d possui as caracteristicas do 3025\n",i);
        }
    }
    return 0;
}