#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int eh_preposicao(const char* palavra) {
    const char* preposicoes[] = {"de", "do", "da", "dos", "das", "e", "em", "a", "o"};
    int qtd = sizeof(preposicoes) / sizeof(preposicoes[0]);
    for (int i = 0; i < qtd; i++) {
        if (strcasecmp(palavra, preposicoes[i]) == 0) {
            return 1;  // É preposição
        }
    }
    return 0;  // Não é preposição
}

int main(){
    char *nome = (char*)malloc(100 * sizeof(char));
    if (nome == NULL){
        printf("Memória insuficiente\n");
        exit(1);
    }

    printf("Digite seu nome completo: ");
    scanf(" %[^\n]", nome);

    char *palavra = strtok(nome, " ");
    int primeiro = 1;

    while (palavra != NULL) {
        if (!eh_preposicao(palavra)) {
            if (!primeiro) {
                printf(".");
            }
            printf("%c", toupper(palavra[0]));
            primeiro = 0;
        }
        palavra = strtok(NULL, " ");
    }
    printf(".\n");

    free(nome);
    return 0;
}