#include <stdio.h>

int conversao_binaria(int n, int *vetor_binario, int tamanho, int tamanho_fixo)
{
    vetor_binario[tamanho] = (n % 2);
    n /= 2;

    if(tamanho > 0)
    {
        tamanho--;
        return conversao_binaria(n, vetor_binario, tamanho, tamanho_fixo);
    }

    if(tamanho == 0)
    {
        int indice, binario = 0;
        for(indice = 0; indice < tamanho_fixo; indice++)
        {
            if(indice == 0)
            {
                if(vetor_binario[indice] == 0)
                    binario = 0;
                else
                    binario = 1;
            }
            else
            {
                if(vetor_binario[indice] == 0)
                    binario *= 10;
                else
                    binario = (binario * 10) + 1;
            }
        }
        return binario;
    }
    return 0;
}

int main(void)
{
    int n, indice, tamanho, tamanho_fixo, numero_binario;

    // Teste 1: n = 6
    n = 6;
    tamanho = 0;
    for(indice = n; indice > 0; )
    {
        indice /= 2;
        tamanho++;
    }
    tamanho_fixo = tamanho;
    int vetor_binario[tamanho_fixo];
    tamanho--;
    // Passos:
    // vetor_binario[2] = 0, n=3
    // vetor_binario[1] = 1, n=1
    // vetor_binario[0] = 1, n=0
    // vetor_binario = [1,1,0]
    numero_binario = conversao_binaria(n, vetor_binario, tamanho, tamanho_fixo);
    printf("n=6 -> binario: %d\n", numero_binario);

    // Teste 2: n = 13
    n = 13;
    tamanho = 0;
    for(indice = n; indice > 0; )
    {
        indice /= 2;
        tamanho++;
    }
    tamanho_fixo = tamanho;
    int vetor_binario2[tamanho_fixo];
    tamanho--;
    // Passos:
    // vetor_binario[3] = 1, n=6
    // vetor_binario[2] = 0, n=3
    // vetor_binario[1] = 1, n=1
    // vetor_binario[0] = 1, n=0
    // vetor_binario = [1,1,0,1]
    numero_binario = conversao_binaria(n, vetor_binario2, tamanho, tamanho_fixo);
    printf("n=13 -> binario: %d\n", numero_binario);

    // Teste 3: n = 1
    n = 1;
    tamanho = 0;
    for(indice = n; indice > 0; )
    {
        indice /= 2;
        tamanho++;
    }
    tamanho_fixo = tamanho;
    int vetor_binario3[tamanho_fixo];
    tamanho--;
    // Passos:
    // vetor_binario[0] = 1, n=0
    // vetor_binario = [1]
    numero_binario = conversao_binaria(n, vetor_binario3, tamanho, tamanho_fixo);
    printf("n=1 -> binario: %d\n", numero_binario);

    return 0;
}
/*Saida:
n=6 -> binario: 110
n=13 -> binario: 1101
n=1 -> binario: 1
*/