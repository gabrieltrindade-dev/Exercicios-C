#include <stdio.h>
int divs(int n,int*max,int*min);

int main(){

    int num,primo,max,min;

    printf("digite um numero: ");
    scanf("%d",&num);

    primo = divs(num,&max,&min);
    if(primo==0){
        printf("numero primo");
    }
    else{
        printf("numero nao primo\n o menor divisor %d\n o maior divisor %d\n",min,max);
    }
    return 0;
    }

    int divs(int n,int*max,int*min){
    int menor=0;
    *min=0;
    *max=0;
    for(int i=2; i<n;i++){
        if (n%i==0){
            *max=i;
            if(menor==0){
                *min=i;
                menor=1;
            }
        }
    }
    if(menor==0){
        return 0;
    }
    else{
        return 1;
    }
    return 0;
}