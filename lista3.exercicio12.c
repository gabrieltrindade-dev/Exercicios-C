#include <stdio.h>
#include <conio.h>

#define MAX 80

int main(){
    char v[MAX];
    char ch;
    int i;
    printf("digite a frase: ");
    for (i =0;i<80;i++){
        ch=getch();
        if (ch=='\r'){
            break;
        }
        putchar(ch);
        v[i]=ch;
    }
    printf("\npalavras separadas:\n");
    for(int j=0;j<i;j++){
        if (v[j]==' '){
            printf("\n");
        }
        else{
            printf("%c",v[j]);
        }
    }
    return 0;
}