struct aluno {
int mat; /* Matricula do aluno */
char nome[81]; /* Nome do aluno */
};
typedef struct aluno Aluno;
struct prova {
Aluno a; /* Aluno que fez a prova */
float q1, q2, q3, q4; /* Nota em cada questao */
};
typedef struct prova Prova;
void ordena(int n, Prova** v)
{
int fim,i;
for(fim=n-1; fim>0; fim--)
for(i=0; i<fim; i++)
if(compara(v[i],v[i+1]))
troca(&v[i],&v[i+1]);

}
int compara(Prova* v,Prova* v2 ){
if ((v->q1+v->q2+v->q3+v->q4)<(v2->q1+v2->q2+v2->q3+v2->q4)){
    return 1;
}
else if((v->q1+v->q2+v->q3+v->q4)>(v2->q1+v2->q2+v2->q3+v2->q4)){
    return 0;
}
else{
    if (strcmp(v->a.nome,v2->a.nome)>0){
        return 1;
    }
    else{
        return 0;
    }
}
}

void troca(Prova**v,Prova**v2){
    Prova *temp= *v2;
    *v2=*v;
    *v=temp;
}