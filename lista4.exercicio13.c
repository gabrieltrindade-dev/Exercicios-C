#include <stdio.h>
#include <string.h>
#define MAX 51
int main(){
char string[MAX];
char str2[MAX]={0};
printf("digite a string\n");
scanf("%s",string);
int i=0;
int k=0;
while (string[i]!='\0'){
    int esta=0;
    int len=strlen(str2);
    for (int j=0;j<len;j++){
        if (string[i] == str2[j])
        {
            esta=1;
            break;
        }
    }
    int count=0;
    if (!esta){
    for (int j=0; string[j]!='\0';j++){
        if (string[i] == string[j]){
            count++;
        }
    }
    printf(" '%c' = %d",string[i],count);
    str2[k++]=string[i];}
    i++;
}
return 0;
}