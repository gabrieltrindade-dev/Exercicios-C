#include <stdio.h>
#include <stdlib.h>
#define MAX 50
struct aluno{
  char aluno[51];
  float media;
};
void le(struct aluno turma[MAX]){
    for (int i=0;i<MAX;i++){
        printf("digite o nome do aluno %d\n",i);
        scanf(" %50s",turma[i].aluno);
        printf("digite a media desse aluno\n");
        scanf( "%f",&turma[i].media);
    }
    getchar();
}
void imprime(struct aluno turma[MAX]){
    for (int i=0;i<MAX;i++){
        printf("nome: %s, media: %.2f\n",turma[i].aluno,turma[i].media);
    }


}
void ordena_medias(struct aluno turma[MAX]){
    struct aluno temp;
    for (int i=0;i<MAX-1;i++){
        for (int j=0;j<MAX-1-i;j++){
            if (turma[j].media>turma[j+1].media){
                temp=turma[j];
                turma[j]=turma[j+1];
                turma[j+1]=temp;
            }
        }
    }
}

int main (void) {
struct aluno turma[MAX];
le( turma );

puts (" Imprimindo dados lidos da turma.");
puts (" Digite qualquer coisa para continuar .");
getchar ();
imprime ( turma );
ordena_medias ( turma );
puts (" Imprimindo dados ordenados da turma.");
puts (" Digite qualquer coisa para continuar .");
getchar ();
imprime ( turma );
getchar ();
}