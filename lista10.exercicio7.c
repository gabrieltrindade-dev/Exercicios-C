#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
FILE*fp;
fp=fopen("numeros.txt","rt");
if(fp==NULL){
    printf("ERRO\n");
    exit(1);
}
int capacidade=10;
float*vet=(float*)malloc(capacidade*sizeof(float));
if(vet==NULL){
    printf("ERRO\n");
    fclose(fp);
    exit(2);
}
float num=0.0f;
int c=0;
while(fscanf(fp,"%f",&num)==1){
    if (c>=capacidade){
        capacidade*=2;
        vet=(float*)realloc(vet,capacidade*sizeof(float));
        if(vet==NULL){
            printf("ERRO\n");
            fclose(fp);
            exit(1);
            }
    }
    vet[c]=num;
    c++;
}

for (int i=0;i<c-1;i++){
    for (int j=0;j<c-i-1;j++){
        if(vet[j+1]<vet[j]){
            float temp=vet[j];
            vet[j]=vet[j+1];
            vet[j+1]=temp;
        }

    }
}
fclose(fp);

FILE*fp2;
fp2=fopen("numeros.bin","wb");
if(fp2==NULL){
    printf("ERRO\n");
    exit(3);
}
fwrite(vet,sizeof(float),c,fp2);
fclose(fp2);
free(vet);

printf("Arquivo numeros.bin gravado com sucesso com %d números ordenados.\n", c);
return 0;
}