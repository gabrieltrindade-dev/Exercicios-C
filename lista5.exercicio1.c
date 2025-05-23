#include <stdio.h>
#include <stdlib.h>

void funcao(char *str, int *qnt) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||
            str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'){
            (*qnt)++;
        }
    }
}

int main() {
    int qnt_vogal = 0;
    char *string = (char*)malloc(1000 * sizeof(char));
    if (string == NULL) {
        printf("memoria insuficiente\n");
        exit(1);
    }

    printf("digite a string: ");
    scanf("%999[^\n]", string);

    funcao(string, &qnt_vogal);

    printf("o numero de vogais e: %d\n", qnt_vogal);

    free(string);
    return 0;
}