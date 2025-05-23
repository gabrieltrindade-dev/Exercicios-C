#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char*string=(char*)malloc(51*sizeof(char));
    char*possui=(char*)malloc(51*sizeof(char));
    if (string==NULL||possui==NULL){
        printf("memoria insuficiente\n");
        exit(1);
    }

    printf("digite uma string MAX 50 caracter\n");
    scanf(" %[^\n]",string);

    int len=strlen(string);
    int count;
    int esta;
    char temp[2];
    possui[0]='\0';
    for (int i=0;i<len;i++){
        count=0;
        esta=0;
        for (int j=0;possui[j]!='\0';j++){
            if (string[i]==possui[j]){
                esta=1;
                break;
            }
        }
        if (esta!=1){
            for (int j=0;string[j]!='\0';j++){
                if (string[i]==string[j]){
                    count++;
                }
            }
            temp[0]=string[i];
            temp[1]='\0';
            printf("'%c'=%d, ",string[i],count);
            strcat(possui,temp);
        }
    }
    free(possui);
    free(string);
    return 0;
}