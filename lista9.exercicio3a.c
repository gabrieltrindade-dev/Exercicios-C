Assalariados * cadastra(char *nome, char sexo, int idade, float salario, char *estado){
    Assalariados *pessoa = (Assalariados*)malloc(sizeof(Assalariados));
    if(pessoa==NULL){
        printf("Memoria invalida");
        exit (1);
    }
    strcpy(pessoa->nome, nome);
    pessoa->sexo=sexo;
    pessoa->idade=idade;
    pessoa->salario=salario;
    strcpy(pessoa->estado, estado);
    return pessoa;
}