Aluno* fillAluno(){
    Aluno* ler_aluno = malloc(sizeof(Aluno));
    if(ler_aluno == NULL){
        printf("memoria insuficiente\n");
        exit(1);
    }

    printf("digite a matricula do aluno\n");
    scanf(" %d", &ler_aluno->matricula);

    ler_aluno->vNotas = malloc(5 * sizeof(float));
    if(ler_aluno->vNotas == NULL){
        printf("memoria insuficiente\n");
        free(ler_aluno);
        exit(1);
    }

    printf("digite as notas do aluno\n");
    for (int i = 0; i < 5; i++){
        scanf(" %f", &ler_aluno->vNotas[i]);
    }

    printf("digite o nome do aluno\n");
    scanf(" %99s", ler_aluno->nome);

    return ler_aluno;
}
