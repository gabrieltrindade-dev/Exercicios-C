#include <stdio.h>
#define MAX 100

float max_vet(int n, float *vet);

int main() {
    int n;
    float vet[MAX];

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Digite um numero no vetor: ");
        scanf("%f", &vet[i]);
    }

    float maior = max_vet(n, vet);
    printf("O maior numero no vetor é: %.2f\n", maior);

    return 0;
}

float max_vet(int n, float *vet) {
    float maior = vet[0];
    for (int i = 1; i < n; i++) {
        if (vet[i] > maior) {
            maior = vet[i];
        }
    }
    return maior;
}