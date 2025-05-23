#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char*string=(char*)malloc(21*sizeof(char));
    char*invertida=(char*)malloc(21*sizeof(char));
    if (string==NULL||invertida==NULL){
        printf("memoria insuficiente\n");
        exit(1);
    }

    printf("digite a string\n");
    scanf(" %[^\n]",string);

    int len=strlen(string);
    int i;
    for(i=0;i<len;i++){
        invertida[i]=string[len-i-1];
    }
    invertida[i]='\0';

    printf("%s\n",invertida);

    free(invertida);
    free(string);
    return 0;
}