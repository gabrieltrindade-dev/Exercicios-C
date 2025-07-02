#include <stdio.h>
#include <stdlib.h>

typedef struct notas {
    float geral; 
    float especifica; 
} Notas;


typedef struct local {
    char ender[81]; 
    int sala; 
} Local;

typedef struct data {
    int dia, mes, ano;
} Data;

typedef struct candidato {
    int inscr; 
    char nome[81]; 
    Data nasc; 
    Local *loc;
    Notas nt;
} Candidato;

int main(){
    int n;
    printf("Digite o numero de canditatos: ");
    scanf("%d", &n);
    Candidato **candidatos = (Candidato **)malloc(n * sizeof(Candidato*));
    if(candidatos==NULL){
        printf("Memoria invalida");
        exit (1);
    }
    for(int i=0; i<n; i++){
        candidatos[i]=(Candidato*)malloc(sizeof(Candidato));
        if(candidatos[i]==NULL){
            printf("Memoria invalida");
            exit (1);
        }
    }
    for(int i=0; i<n; i++){
        candidatos[i]->loc = (Local*)malloc(sizeof(Local));
        if(candidatos[i]->loc==NULL){
            printf("Memoria invalida");
            exit (1);
        }
    }
    for(int i=0; i<n; i++){
        printf("Digite seu numero de inscricao: ");
        scanf("%d", &candidatos[i]->inscr);
        printf("Digite seu nome: ");
        scanf(" %[^\n]", &candidatos[i]->nome);
        printf("Digite sua data de nascimento: ");
        scanf("%d %d %d", &candidatos[i]->nasc.dia, &candidatos[i]->nasc.mes, &candidatos[i]->nasc.ano);
        printf("Digite seu endereco: ");
        scanf(" %[^\n]", &candidatos[i]->loc->ender);
        printf("Digite sua sala: ");
        scanf("%d", &candidatos[i]->loc->sala);
        printf("Digite sua nota geral e especifica: ");
        scanf("%f %f", &candidatos[i]->nt.geral, &candidatos[i]->nt.especifica);
    }
    for(int i=0; i<n; i++){
        printf("\nNumero de inscricao: %d\n", candidatos[i]->inscr);
        printf("Nome: %s\n", candidatos[i]->nome);
        printf("Data de nascimento: %d/%d/%d\n", candidatos[i]->nasc.dia, candidatos[i]->nasc.mes, candidatos[i]->nasc.ano);
        printf("Endereco: %s\n", candidatos[i]->loc->ender);
        printf("Sala: %d\n", candidatos[i]->loc->sala);
        printf("Nota geral e especifica: %f %f", candidatos[i]->nt.geral, candidatos[i]->nt.especifica);
    }
    for(int i=0; i<n; i++){
        free (candidatos[i]->loc);
        free (candidatos[i]);
    }
    free (candidatos);
    return 0;
}