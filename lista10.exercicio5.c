#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
int main(){
char arquivo[MAX];
printf("digite o nome do arquivo\n");
scanf("%s",arquivo);

FILE*fp;
fp=fopen(arquivo,"r");
if(fp==NULL){
    printf("ERRO\n");
    exit(1);
}
int capacidade_inicial=10;
float*vet=(float*)malloc(capacidade_inicial*sizeof(float));
if (vet==NULL){
    printf("erro de alocacao\n");
    fclose(fp);
    exit(2);
}

int c=0;
float num=0.0f;
while (fscanf(fp,"%f",&num)==1){
    if (c>=capacidade_inicial){
        capacidade_inicial*=2;
        vet=(float*)realloc(vet,capacidade_inicial*sizeof(float));
        if (vet==NULL){
            printf("erro de alocacao\n");
            fclose(fp);
            exit(3);
        }
    }
    vet[c]=num;
    c++;
}

if(c==0){
    printf("nada foi encontrado\n");

}
else{
float media=0;
for (int i=0;i<c;i++){
    media+=vet[i];
}
media=media/c;

printf("a media: %.2f",media);
}

fclose(fp);
return 0;
}