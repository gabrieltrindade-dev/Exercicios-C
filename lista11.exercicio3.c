#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    char nome[81];
    int matricula;
    float media;
    struct aluno* prox;
} Aluno;

Aluno* incluir(Aluno* lista, char nome[], int matricula, float media) {
    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    if (novo == NULL) {
        printf("Erro de memória\n");
        exit(1);
    }
    strcpy(novo->nome, nome);
    novo->matricula = matricula;
    novo->media = media;
    novo->prox = lista;
    return novo;
}

void imprimir(Aluno* lista) {
    Aluno* p = lista;
    while (p != NULL) {
        printf("Nome: %s | Matricula: %d | Média: %.2f\n", p->nome, p->matricula, p->media);
        p = p->prox;
    }
}

Aluno* excluir(Aluno* lista, int matricula) {
    Aluno* p = lista;
    Aluno* ant = NULL;
    while (p != NULL) {
        if (p->matricula == matricula) {
            if (ant == NULL) {
                lista = p->prox;
            } else {
                ant->prox = p->prox;
            }
            free(p);
            printf("Aluno excluído!\n");
            return lista;
        }
        ant = p;
        p = p->prox;
    }
    printf("Aluno não encontrado!\n");
    return lista;
}

void alterar(Aluno* lista, int matricula, float nova_media) {
    Aluno* p = lista;
    while (p != NULL) {
        if (p->matricula == matricula) {
            p->media = nova_media;
            printf("Aluno alterado!\n");
            return;
        }
        p = p->prox;
    }
    printf("Aluno não encontrado!\n");
}

Aluno* carregar_lista(const char* nome_arquivo) {
    FILE* bin = fopen(nome_arquivo, "rb");
    if (bin == NULL) {
        return NULL;
    }
    Aluno temp;
    Aluno* lista = NULL;
    while (fread(temp.nome, sizeof(char), 81, bin) == 81 &&
           fread(&temp.matricula, sizeof(int), 1, bin) == 1 &&
           fread(&temp.media, sizeof(float), 1, bin) == 1) {
        lista = incluir(lista, temp.nome, temp.matricula, temp.media);
    }
    fclose(bin);
    return lista;
}

void salvar_lista(Aluno* lista, const char* nome_arquivo) {
    FILE* f = fopen(nome_arquivo, "wb");
    if (f == NULL) {
        printf("Erro ao salvar o arquivo.\n");
        return;
    }
    Aluno* p = lista;
    while (p != NULL) {
        fwrite(p->nome, sizeof(char), 81, f);
        fwrite(&p->matricula, sizeof(int), 1, f);
        fwrite(&p->media, sizeof(float), 1, f);
        p = p->prox;
    }
    fclose(f);
}

int main() {
    Aluno* lista = carregar_lista("arquivo.bin");
    int menu;
    char nome[81];
    int matricula;
    float media;
    while (1) {
        printf("\n1 - Imprimir\n2 - Excluir\n3 - Incluir\n4 - Alterar\nOutro - Sair\nEscolha: ");
        if (scanf("%d", &menu) != 1) break;
        if (menu == 1) {
            imprimir(lista);
        }
        else if (menu == 2) {
            printf("Matrícula a excluir: ");
            scanf("%d", &matricula);
            lista = excluir(lista, matricula);
        }
        else if (menu == 3) {
            printf("Nome: ");
            getchar();
            fgets(nome, 81, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            printf("Matrícula: ");
            scanf("%d", &matricula);
            printf("Média: ");
            scanf("%f", &media);
            lista = incluir(lista, nome, matricula, media);
        }
        else if (menu == 4) {
            printf("Matrícula do aluno a alterar: ");
            scanf("%d", &matricula);
            printf("Nova média: ");
            scanf("%f", &media);
            alterar(lista, matricula, media);
        }
        else {
            break;
        }
    }
    salvar_lista(lista, "arquivo.bin");
    while (lista != NULL) {
        Aluno* temp = lista;
        lista = lista->prox;
        free(temp);
    }
    return 0;
}
