#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct notas {
    float geral, especifica;
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

void lerCandidatos(Candidato ***v, int *n) {
    printf("Numero de candidatos: ");
    scanf("%d", n);
    *v = malloc(*n * sizeof(Candidato*));
    for (int i = 0; i < *n; i++) {
        (*v)[i] = malloc(sizeof(Candidato));
        (*v)[i]->loc = malloc(sizeof(Local));
        printf("\nCandidato %d\n", i + 1);
        printf("Inscricao: "); scanf("%d", &(*v)[i]->inscr);
        printf("Nome: "); scanf(" %[^\n]", (*v)[i]->nome);
        printf("Nascimento (dia mes ano): ");
        scanf("%d %d %d", &(*v)[i]->nasc.dia, &(*v)[i]->nasc.mes, &(*v)[i]->nasc.ano);
        printf("Endereco: "); scanf(" %[^\n]", (*v)[i]->loc->ender);
        printf("Sala: "); scanf("%d", &(*v)[i]->loc->sala);
        printf("Notas (geral e especifica): ");
        scanf("%f %f", &(*v)[i]->nt.geral, &(*v)[i]->nt.especifica);
    }
}

void imprimirCandidatos(Candidato **v, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nCandidato %d\n", i + 1);
        printf("Inscricao: %d\nNome: %s\nNascimento: %02d/%02d/%04d\n",
            v[i]->inscr, v[i]->nome, v[i]->nasc.dia, v[i]->nasc.mes, v[i]->nasc.ano);
        printf("Endereco: %s\nSala: %d\nNotas: %.2f %.2f\n",
            v[i]->loc->ender, v[i]->loc->sala, v[i]->nt.geral, v[i]->nt.especifica);
    }
}

void alterarLocal(Candidato **v, int n) {
    int inscr, encontrado = 0;
    printf("Digite o numero de inscricao do candidato: ");
    scanf("%d", &inscr);
    for (int i = 0; i < n; i++) {
        if (v[i]->inscr == inscr) {
            printf("Novo endereco: ");
            scanf(" %[^\n]", v[i]->loc->ender);
            printf("Nova sala: ");
            scanf("%d", &v[i]->loc->sala);
            printf("Local de prova atualizado com sucesso.\n");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado)
        printf("Candidato nao encontrado.\n");
}

void liberar(Candidato **v, int n) {
    for (int i = 0; i < n; i++) {
        free(v[i]->loc);
        free(v[i]);
    }
    free(v);
}

int main() {
    Candidato **candidatos = NULL;
    int n = 0, opcao;

    do {
        printf("\n1 - Ler\n2 - Imprimir\n3 - Alterar local\n0 - Sair\nOpcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            if (candidatos) liberar(candidatos, n);
            lerCandidatos(&candidatos, &n);
        } else if (opcao == 2) {
            if (candidatos) imprimirCandidatos(candidatos, n);
            else printf("Nenhum candidato cadastrado.\n");
        } else if (opcao == 3) {
            if (candidatos) alterarLocal(candidatos, n);
            else printf("Nenhum candidato cadastrado.\n");
        }

    } while (opcao != 0);

    if (candidatos) liberar(candidatos, n);
    return 0;
}
