#include<stdio.h> //incluir a bliblioteca padrao de entrada e saida
#include<string.h> // incluir a biblioteca padrao de string
main(void) //funcao principal do codigo
{
 char texto[]= "foi muito facil"; //inicializa um vetor do tipo char (string) que recebe a frase"foi muito facil\0"
 int i; //efine uma variavel i do tipo inteiro
 for (i = 0; texto[i]!='\0'; i++)  // um loop de repetiчуo o i recebe 0, o loop ocorre enquanto o \0 nao щ encontrado, e o i щ incrementado no fim de cada repeticao
 {
 if (texto[i] == ' ') break;  // se o caracter em texto da posicao i receber espaco, o loop щ interrompido
 }
 i++; //o i щ incrementado
 for ( ; texto[i]!='\0'; i++) //um loop que ocorre atщ o fim da string, quando o caracter \0 щ encontrado na posicao i, o i щ incrementado atщ o fim do loop
 {
 printf("%c", texto[i]);  //imprime a cada repeticao o caracter em texto na posicao i
 }//o programa imprime muito facil, pois no primeiro loop para quando o primeiro espaco щ encontrado,logo o i щ incrementado e no segundo loop o i continua com o valor anterior entao a string vai sendo imprimida na posicao[4] atщ o \0
}