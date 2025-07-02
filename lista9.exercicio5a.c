#include <stdlib.h>
#include <stdio.h>

typedef struct endereco {
    char rua[100];
    int numero;
} Endereco;

typedef struct notas {
    float p1, p2, p3;
} Notas;

typedef struct aluno {
    int mat;
    char nome[81];
    Notas nota;
    Endereco *end;
} Aluno;

Aluno **alocaAlunos(int n) {
    Aluno **resultado = (Aluno **)malloc(n * sizeof(Aluno *));
    if (resultado == NULL) {
        printf("Memoria insuficiente\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        resultado[i] = malloc(sizeof(Aluno));
        if (resultado[i] == NULL) {
            printf("Memoria insuficiente\n");
            exit(1);
        }

        resultado[i]->end = malloc(sizeof(Endereco));
        if (resultado[i]->end == NULL) {
            printf("Memoria insuficiente\n");
            exit(1);
        }
    }

    return resultado;
}

int main() {
    int n = 3;
    Aluno **alunos = alocaAlunos(n);

    printf("Alocacao bem-sucedida para %d alunos.\n", n);

    // Libera a memória
    for (int i = 0; i < n; i++) {
        free(alunos[i]->end);
        free(alunos[i]);
    }
    free(alunos);

    return 0;
}
