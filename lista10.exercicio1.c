#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct funcionario {
char nome[81]; /* nome do funcionário */
float valor_hora; /* valor da hora de trabalho em Reais */
int horas_mes; /* horas trabalhadas em um mês */
};
typedef struct funcionario Funcionario;

void carrega(int n, Funcionario** vet, char* arquivo){
FILE*fp;
fp=fopen(arquivo,"r");
if(fp==NULL){
    printf("ERRO");
    exit(1);
}
char linha[81];
int i=0;
int boll=0;
while(fgets(linha,sizeof(linha),fp)!=NULL && i<n){
    linha[strcspn(linha, "\n")] = '\0';

    Funcionario*func=(Funcionario*)malloc(sizeof(Funcionario));
    if(func==NULL){
        printf("memoria insuficiente\n");
        fclose(fp);
        exit(1);
    }
    if (boll==0){
        strcpy(func->nome,linha);
        boll=1;
    }
    else{
        sscanf(linha, "%f %d", &func->valor_hora, &func->horas_mes);
        vet[i]=func;
        boll=0;
        i++;
    }

}



fclose(fp);
}