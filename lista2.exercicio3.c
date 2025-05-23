#include <stdio.h>

int main(){
    int n;
    printf("Defina a quantidade de termos:  ");
    scanf("%d",&n);
    while (n <= 0) {
        printf("ERRO!!! Insira um número maior que zero: ");
        scanf("%d", &n);
    }
    int t1=1;
    int t2=1;
    int t3;
    int i=2;
    if(n==1){
        printf("1");
    }
    else if(n==2){
        printf("1 1");
    }
    else{
        printf("1 1 ");
        while(i<n){
            t3=t1+t2;
            t1=t2;
            t2=t3;
            printf("%d ", t3);
            i++;
        }
    }
    return 0;
}