#include <stdio.h>

int mdc(int x, int y);

int main(){
    int num, num2, maxD;
    printf("Digite os numeros: ");
    scanf("%d %d", &num,&num2);
    maxD = mdc(num, num2);
    printf("O mdc de %d e %d eh %d", num, num2, maxD);
    return 0;
}

int mdc(int x, int y){
    int max=1;
    if(x>y){
        for(int i=1; i<x; i++){
            if(x%i==0 && y%i==0){
                max = i;
            }
        }
    }
    else{
        for(int i=1; i<y; i++){
            if(x%i==0 && y%i==0){
                max = i;
            }
        }
    }
    return max;
}