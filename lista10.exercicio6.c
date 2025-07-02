#include <stdio.h>
#include <stdlib.h>

int main() {
    char arquivo[20];
    FILE *fp;

    for (int i = 1; i <= 10; i++) {
        sprintf(arquivo, "teste%02d.txt", i);
        fp = fopen(arquivo, "w");
        if (fp == NULL) {
            printf("ERRO\n");
            exit(1);
        }

        fprintf(fp, "Texto do arquivo %d\n", i);
        fclose(fp);
    }

    return 0;
}
