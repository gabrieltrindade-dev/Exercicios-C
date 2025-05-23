#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char*palavra1=(char*)malloc(100*sizeof(char));
    char*palavra2=(char*)malloc(100*sizeof(char));
    if(palavra1==NULL){
        printf("memoria insuficiente\n");
        exit(1);
    }
    if(palavra2==NULL){
        printf("memoria insuficiente\n");
        exit(2);
    }
    printf("digite uma palavra\n");
    scanf(" %99s",palavra1);
    printf("digite outra palavra\n");
    scanf(" %99s",palavra2);

    int len1=strlen(palavra1);
    int len2=strlen(palavra2);
    int igual=1;
    if (len1!=len2){
        igual=0;
    }
    else{
        for (int i=0;i<len1;i++){
            if (palavra1[i]!=palavra2[i]){
                igual=0;
            }
        }
    }
    int j;
    int contido=0;
    if (len2 <= len1) {
        for (int i = 0; i <= len1 - len2; i++) {
            if (palavra2[0] == palavra1[i] && contido == 0) {
                j = 0;
                while (palavra2[j] != '\0' && palavra2[j] == palavra1[i + j]) {
                    j++;
                }
                if (palavra2[j] == '\0') {
                    contido = 1;
                    break;
                }
            }
        }
    }
    if (igual==0){
        printf("as palavras sao diferentes\n");
    }
    else{
        printf("as palavras sao iguais\n");
    }
    if(contido==1){
        printf("a palavra2 esta contido em 1\n");
    }
    else{
        printf("a palavra 2 nao esta contida em 1\n");
    }
    free(palavra1);
    free(palavra2);
    return 0;
}