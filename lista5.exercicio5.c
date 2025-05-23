main(void)
{
char frase[80]="o rato roeu a roupa do rei de roma";
char *p;
p = frase;
p[2]='m';
p[6]='\0';
printf("%s\n", frase);
p = p + 3;
printf("%s\n",p);
printf("%d\n",strlen(frase));
}
/* o programa vai imprimir:
o mato
ato
6
*/