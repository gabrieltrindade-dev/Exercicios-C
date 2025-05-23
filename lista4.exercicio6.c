#include <stdio.h>
#include <string.h>
#include <ctype.h>

int valida_mail(char *s);

int main(){
    char frase[65];
    printf("Digite seu email antes do @: ");
    scanf("%s", frase);
    int result = valida_mail(frase);
    if(result==0){
        printf("A Cadeia %s nao eh valida", frase);
    }
    else{
        printf("A Cadeia %s eh valida", frase);
    }
    return 0;
}

int valida_mail(char *s){
    int len = strlen(s);
    if (len > 64 || len < 2) {
        return 0;
    }

    if (!isalpha(s[0])) {
        return 0;
    }

    int pontoAnterior = 0;
    int countAlnum = 0;
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (!isalnum(c) && c != '.' && c != '-' && c != '_') {
            return 0;
        }
        if (isalnum(c)) {
            countAlnum++; // ADIÇÃO: conta letras e números
        }
        if (c == '.') {
            if (pontoAnterior || i == len - 1) {
                return 0;
            }
            pontoAnterior = 1;
        } else {
            pontoAnterior = 0;
        }
    }
    if (countAlnum < 2) {
        return 0; 
    }
    return 1;
}