#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _ALUNO {
    char nome[81];
    float nota1, nota2;
} ALUNO;

void incluir_aluno(FILE* bin) {
    ALUNO novo;
    printf("Digite o nome do aluno: ");
    scanf(" %80[^\n]", novo.nome);
    printf("Digite a nota 1: ");
    scanf("%f", &novo.nota1);
    printf("Digite a nota 2: ");
    scanf("%f", &novo.nota2);

    fseek(bin, 0, SEEK_END);
    fwrite(&novo, sizeof(ALUNO), 1, bin);
    printf("Aluno incluído com sucesso!\n");
}

void alterar_aluno(FILE* bin, int n) {
    int id;
    printf("Digite o índice do aluno a alterar (0 a %d): ", n - 1);
    scanf("%d", &id);

    if (id < 0 || id >= n) {
        printf("ID inválido!\n");
        return;
    }

    ALUNO a;
    fseek(bin, id * sizeof(ALUNO), SEEK_SET);
    fread(&a, sizeof(ALUNO), 1, bin);

    printf("Nome atual: %s\n", a.nome);
    printf("Digite o novo nome: ");
    scanf(" %80[^\n]", a.nome);
    printf("Digite a nova nota 1: ");
    scanf("%f", &a.nota1);
    printf("Digite a nova nota 2: ");
    scanf("%f", &a.nota2);

    fseek(bin, id * sizeof(ALUNO), SEEK_SET);
    fwrite(&a, sizeof(ALUNO), 1, bin);

    printf("Aluno alterado com sucesso!\n");
}

void consultar_aluno(FILE* bin, int n) {
    int id;
    printf("Digite o índice do aluno a consultar (0 a %d): ", n - 1);
    scanf("%d", &id);

    if (id < 0 || id >= n) {
        printf("Aluno inexistente!\n");
        return;
    }

    ALUNO a;
    fseek(bin, id * sizeof(ALUNO), SEEK_SET);
    fread(&a, sizeof(ALUNO), 1, bin);

    float media = (a.nota1 + a.nota2) / 2.0;
    printf("Nome: %s | Nota1: %.2f | Nota2: %.2f | Média: %.2f\n", a.nome, a.nota1, a.nota2, media);
}

void excluir_aluno(FILE* bin, int* n) {
    int id;
    printf("Digite o índice do aluno a excluir (0 a %d): ", (*n) - 1);
    scanf("%d", &id);

    if (id < 0 || id >= *n) {
        printf("ID inválido!\n");
        return;
    }

    ALUNO* alunos = (ALUNO*)malloc((*n) * sizeof(ALUNO));
    if (alunos == NULL) {
        printf("Erro de memória!\n");
        return;
    }

    rewind(bin);
    fread(alunos, sizeof(ALUNO), *n, bin);

    for (int i = id; i < (*n) - 1; i++) {
        alunos[i] = alunos[i + 1];
    }

    fclose(bin);
    bin = fopen("arquivo.bin", "wb");
    if (bin == NULL) {
        printf("Erro ao reabrir o arquivo!\n");
        free(alunos);
        return;
    }

    fwrite(alunos, sizeof(ALUNO), (*n) - 1, bin);
    *n = *n - 1;

    free(alunos);

    printf("Aluno excluído com sucesso!\n");
}

int main() {
    FILE* bin = fopen("arquivo.bin", "rb+");
    if (bin == NULL) {
        bin = fopen("arquivo.bin", "wb+");
        if (bin == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }
    }

    int opcao;
    int tam;

    while (1) {
        // Atualiza quantidade de alunos
        fseek(bin, 0, SEEK_END);
        long tamanho = ftell(bin);
        tam = tamanho / sizeof(ALUNO);

        printf("\n===== MENU =====\n");
        printf("1 - Incluir aluno\n");
        printf("2 - Alterar aluno\n");
        printf("3 - Consultar aluno\n");
        printf("4 - Excluir aluno\n");
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluir_aluno(bin);
                break;
            case 2:
                alterar_aluno(bin, tam);
                break;
            case 3:
                consultar_aluno(bin, tam);
                break;
            case 4:
                excluir_aluno(bin, &tam);
                bin = fopen("arquivo.bin", "rb+"); // reabre após exclusão
                if (bin == NULL) {
                    printf("Erro ao reabrir o arquivo.\n");
                    return 2;
                }
                break;
            case 5:
                fclose(bin);
                printf("Encerrando o programa.\n");
                return 0;
            default:
                printf("Opção inválida!\n");
        }
    }
}
