#include <stdio.h>
#include <stdlib.h>
struct aluno{
  char aluno[51];
  float media;
};
typedef struct aluno ALUNO;
void ordena (ALUNO turma[], int tam) {
int i, foraOrdem , jaOrdenados = 0;
ALUNO temp;
do {
foraOrdem = 0;
for (i = 0; i < 4 - 1 - jaOrdenados ; i++) {
if (turma[i]. media > turma[i+1]. media) {
temp = turma[i];
turma[i] = turma[i+1];
turma[i+1] = temp ;
foraOrdem = 1;
}
}
jaOrdenados ++;
} while ( foraOrdem );
}

int main(){
int tam;
printf("digite o tamanho\n");
scanf(" %d",&tam);
ALUNO*turma=(ALUNO*)malloc(tam*sizeof(ALUNO));
if (turma==NULL){
    printf("memoria insuficiente\n");
    exit(1);
}
for (int i=0;i<tam;i++){
    printf("digite o nome do aluno\n");
    scanf(" %50s",turma[i].aluno);
    printf("digite a media desse aluno\n");
    scanf(" %f",&turma[i].media);
}
ordena(turma,tam);
printf("o vetor ja ordenado: \n");
for (int i=0;i<tam;i++){
    printf("aluno %s, media %.2f",turma[i].aluno,turma[i].media);

}


free(turma);
return 0;
}