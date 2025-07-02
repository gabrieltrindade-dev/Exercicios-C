#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char nomeArquivo[100];
    printf("Digite o nome do arquivo .c: ");
    scanf("%s", nomeArquivo);

    FILE *fp = fopen(nomeArquivo, "r");
    if (fp == NULL) {
        printf("ERRO\n");
        exit(1);
    }

    FILE *novo = fopen("novo.c", "w");
    if (novo == NULL) {
        printf("ERRO\n");
        fclose(fp);
        exit(2);
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), fp) != NULL) {
        char *p = linha;
        while (*p == ' ' || *p == '\t') p++;
        if (p[0] == '/' && p[1] == '/') {
            continue;
        }
        fputs(linha, novo);
    }

    fclose(novo);
    fclose(fp);

    novo = fopen("novo.c", "r");
    if (novo == NULL) {
        printf("ERRO\n");
        exit(1);
    }

    char linha2[100];
    while (fgets(linha2, sizeof(linha2), novo) != NULL) {
        printf("%s", linha2);
    }

    fclose(novo);
    return 0;
}
