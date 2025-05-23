#include <stdio.h>
#include <string.h>
#include <ctype.h>

void CamelCase (char *s);

int main(){
    char s[20];
    strcpy(s,"media da turma");
    CamelCase(s);
    printf("CamaleCase: %s", s);
    return 0;
}

void CamelCase (char *s){
    int i =0, j=0, novaPv=0;
    char result[25];
    while(s[i]!='\0'){
        if(s[i]==' '){
            novaPv=1;
        }
        else{
            if(j==0){
                result[j++]=s[i];
            }
            else if(novaPv==1){
                result[j++]= toupper(s[i]);
                novaPv=0;
            }
            else{
                result[j++]=s[i];
            }
        }
        i++;
    }
    strcpy(s,result);
}