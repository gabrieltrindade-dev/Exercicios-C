#include <stdio.h>
#include <stdlib.h>

void repeticao(int *vet, int tam);


int main(){

int tam;
printf("digite o tamanho do vetor\n");
scanf("%d",&tam);

int*vet=(int*)malloc(tam*sizeof(int));
if (vet==NULL){
    printf("memoria insuficiente\n");
    exit(1);
}

printf("digite os numeros no vetor de 0 a 9\n");
for (int i=0;i<tam;i++){
    scanf(" %d",&vet[i]);
}

repeticao(vet,tam);


free(vet);
return 0;
}


void repeticao(int *vet, int tam){
int*vet2=(int*)malloc(tam*sizeof(int));
if (vet2==NULL){
    printf("memoria insuficiente\n");
    exit(2);
}
int tam2=0;
int possui;
for (int i=0;i<tam;i++){
    int count=0;
    for (int j=0;j<tam;j++){
        if (vet[i]==vet[j]){
            count++;
        }
    }
    if (count>1){
        int possui=0;
        for (int k=0;k<tam2;k++){
            if (vet2[k]==vet[i]){
                possui=1;
                break;
            }
        }
            if (possui==0){
                vet2[tam2]=vet[i];
                tam2++;
            }

    }
}

for (int i=0;i<tam2;i++){
    printf("%d, ",vet2[i]);
}

free(vet2);
}