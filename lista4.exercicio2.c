#include <stdio.h>

void listaX(float *vR, float *vS, float *vX,int *qtdx){
    for(int i=0; i<5; i++){
        printf("Valor para lista R: ");
        scanf("%f", &vR[i]);
    }
    for(int i=0; i<10; i++){
        printf("Valor para lista S: ");
        scanf("%f", &vS[i]);
    }
    *qtdx=0;
    for(int i=0; i<5; i++){
        for(int j=0; j<10; j++){
            if(vR[i]==vS[j]){
                int repetido=0;
                for(int k=0; k<*qtdx;k++){
                    if(vX[k]==vR[i]){
                        repetido=1;
                        break;
                    }
                }
                if(repetido==0){
                    vX[*qtdx]=vR[i];
                    (*qtdx)++;
                }
                break;
            }
        }
    }
    
}

int main(){
    float r[5];
    float s[10];
    float x[5];
    int qtdx=0;
    listaX(r, s, x, &qtdx);
    for(int i=0; i<qtdx; i++){
        printf("%.2f ", x[i]);
    }
    return 0;
}