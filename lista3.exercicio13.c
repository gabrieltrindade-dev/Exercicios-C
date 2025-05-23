#include <stdio.h>

int main(){
    int a=1,b=2,c=3,d=4;

    float e=1.1,f=1.2,g=1.3,h=1.4;

    char v[10];

    int x=10;

    int *ponteiro;
    ponteiro=&a;
    *ponteiro=20;

    printf("o endereco de a %p\n",ponteiro);
    printf("valor de a %d\n",*ponteiro);
    ponteiro++;
    if(ponteiro==&b){
        printf("Agora aponta pra b");
        }
    else if(ponteiro==&c){
        printf("Agora aponta pra c");
        }
    else if(ponteiro==&d){
        printf("Agora aponta pra d");
        }
    else if(ponteiro==&e){
        printf("Agora aponta pra e");
        }
    else if(ponteiro==&f){
        printf("Agora aponta pra f");
        }
    else if(ponteiro==&g){
        printf("Agora aponta pra g");
        }
    else if(ponteiro==&h){
        printf("Agora aponta pra h");
        }
    else if(ponteiro==&x){
        printf("Agora aponta pra x");
        }
    printf("endereco: %p  Valor: %d", ponteiro, *ponteiro);
    return 0;
}