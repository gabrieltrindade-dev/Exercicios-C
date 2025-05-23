#include <stdio.h>

void listaY(int *vX, int *vY){
    for(int i=0; i<10; i++){
        printf("Valor para lista x: ");
        scanf("%d", &vX[i]);
    }
    for(int i=0; i<10; i++){
        vY[i] = vX[9-i];
    }
}

int main(){
    int x[10];
    int y[10];
    listaY(x,y);
    for(int i=0; i<10; i++){
        printf("%d\n", y[i]);
    }
    return 0;
}