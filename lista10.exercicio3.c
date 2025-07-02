#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float media (char* mat, char* nome_arquivo){
FILE*fp;
fp=fopen(nome_arquivo,"r");
if(fp==NULL){
    printf("ERRO\n");
    exit(1);
}
char linha[100];
char mat2[21];
float p1,p2,p3;
while(fgets(linha,sizeof(linha),fp)!=NULL){
    linha[strcspn(linha,"\n")]='\0';
    sscanf(linha,"%s %f %f %f",mat2,&p1,&p2,&p3);
    if (strcmp(mat2,mat)==0){
        fclose(fp);
        return (p1+p2+p3)/3;
    }
}

fclose(fp);
return -1.0f;
}