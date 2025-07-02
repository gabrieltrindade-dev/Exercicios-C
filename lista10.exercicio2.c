#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float busca (char* arquivo, char* matricula){
FILE*fp;
fp=fopen(arquivo,"r");
if(fp==NULL){
    printf("ERRo\n");
    exit(1);
}
char linha[100];
int inicio=0;
int fim=8;
float CR;
char mat[21];
while(fgets(linha,sizeof(linha),fp)!=NULL){
    linha[strcspn(linha,"\n")]='\0';
    sscanf(linha, "%s %f", mat,&CR);
    if(strcmp(mat,matricula)==0){
        fclose(fp);
        return CR;
    }
}

return -1.0f;
fclose(fp);
}