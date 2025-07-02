#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
    int dia;
    int mes;
    char nomeMes[12];
} Data;

main()
{
    Data aniversarios[3] = { {5,1,"JANEIRO"},
    {4,2,"FEVEREIRO"},{10,3,"MAIO"} };
    int a;
    Data *p_dt;
    p_dt=&aniversarios[2];
    printf("Nome do mês %d é: %s.", p_dt->mes, p_dt->nomeMes);
    strcpy(p_dt->nomeMes, "MARÇO");
    printf("\nNúmero de letras : %d=", strlen(p_dt->nomeMes));  // O valor mostrado eh 5
    Data p_dt2 = (Data *) malloc(sizeof(Data)); 
    p_dt2 = &aniversarios[0];
}
//O valor mostrado no ultimo print eh 5, mas o meu compilador le o ç como mais um e então mostra 6