#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void ler_senha(char *senha, int max_len) {
    int i = 0;
    char ch;
    printf("Digite a senha: ");
    while (1) {
        ch = getch();
        if (ch == 13) {
            break;
        } else if ((ch == 8 || ch == 127) && i > 0) {
            i--;
            printf("\b \b");
        } else if (i < max_len - 1 && ch >= 32 && ch <= 126) {
            senha[i++] = ch;
            printf("*");
        }
        }
    senha[i] = '\0';
    printf("\n");
}

int main(){
    char*usuario=(char*)malloc(9*sizeof(char));
    char*senha=(char*)malloc(9*sizeof(char));
    char*usuario2=(char*)malloc(9*sizeof(char));
    char*senha2=(char*)malloc(9*sizeof(char));
    if (usuario==NULL||senha==NULL||usuario2==NULL||senha2==NULL){
        printf("memoria insuficiente\n");
        exit(1);
    }
    printf("digite o nome de usuario somente numeros, letras maiusculas e minusculas\n");
    scanf( " %[0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM]",usuario);
    limpar_buffer();
    ler_senha(senha, 9);

    printf("confirme o nome\n");
    scanf( " %[0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM]",usuario2);
    limpar_buffer();
    ler_senha(senha2, 9);

    if(strcmp(usuario,usuario2)==0&&strcmp(senha,senha2)==0){
        printf("OK\n");
    }
    else{
        printf("acesso negado\n");
    }

    free(senha2);
    free(usuario2);
    free(senha);
    free(usuario);
    return 0;
}