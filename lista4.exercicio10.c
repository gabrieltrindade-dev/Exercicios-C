#include <stdio.h>
#include <string.h>

#define N 20

int otimo(char resp[N][20]) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (strcmp(resp[i], "otimo") == 0) {
            count++;
        }
    }
    return count;
}

float dif_perc(char resp[N][20]) {
    int bom = 0, reg = 0;
    for (int i = 0; i < N; i++) {
        if (strcmp(resp[i], "bom") == 0) {
            bom++;
        }
        if (strcmp(resp[i], "regular") == 0) {
            reg++;
        }
    }
    if (reg == 0) {
        return 0.0;
    }
    return ((float)(bom - reg) / reg) * 100;
}

float media_ruim(int id[N], char resp[N][20]) {
    int soma = 0, count = 0;
    for (int i = 0; i < N; i++) {
        if (strcmp(resp[i], "ruim") == 0) {
            soma += id[i];
            count++;
        }
    }
    if (count == 0) {
        return 0.0;
    }
    return (float)soma / count;
}

void pessimo(int id[N], char resp[N][20], float *perc, int *maior) {
    int p = 0;
    *maior = -1;
    for (int i = 0; i < N; i++) {
        if (strcmp(resp[i], "pessimo") == 0) {
            p++;
            if (id[i] > *maior) {
                *maior = id[i];
            }
        }
    }
    *perc = ((float)p / N) * 100;
}

int dif_idade(int id[N], char resp[N][20]) {
    int ot = -1, ru = -1;

    for (int i = 0; i < N; i++) {
        if (strcmp(resp[i], "otimo") == 0 && id[i] > ot) {
            ot = id[i];
        }
        if (strcmp(resp[i], "ruim") == 0 && id[i] > ru) {
            ru = id[i];
        }
    }

    if (ot == -1 || ru == -1) {
        return 0;
    }

    return ot - ru;
}

int main() {
    int id[N];
    char resp[N][20];

    for (int i = 0; i < N; i++) {
        printf("Digite a idade do espectador %d: ", i + 1);
        scanf("%d", &id[i]);

        printf("Digite a opiniao do espectador %d (otimo, bom, regular, ruim, pessimo): ", i + 1);
        scanf("%s", resp[i]);
    }

    int count_ot = otimo(resp);
    printf("\nQuantidade de respostas 'otimo': %d\n", count_ot);

    float perc = dif_perc(resp);
    printf("Diferenca percentual entre 'bom' e 'regular': %.2f%%\n", perc);

    float media = media_ruim(id, resp);
    printf("Media de idade das pessoas que responderam 'ruim': %.2f\n", media);

    int maior_id;
    pessimo(id, resp, &perc, &maior_id);
    printf("Porcentagem de respostas 'pessimo': %.2f%%\n", perc);
    printf("Maior idade entre as pessoas que responderam 'pessimo': %d\n", maior_id);

    int dif = dif_idade(id, resp);
    printf("Diferenca de idade entre a maior idade que respondeu 'otimo' e a maior idade que respondeu 'ruim': %d anos\n", dif);

    return 0;
}