Materia * fillMateria(int numAlunos){
    Materia *ler_materia = malloc(sizeof(Materia));
    if(ler_materia == NULL){
        printf("memoria insuficiente\n");
        exit(1);
    }

    ler_materia->V = (Aluno*) malloc(numAlunos * sizeof(Aluno));
    if (ler_materia->V == NULL){
        printf("memoria insuficiente\n");
        free(ler_materia);
        exit(1);
    }

    ler_materia->nAlunos = numAlunos;

    for (int i = 0; i < numAlunos; i++){
        Aluno *temp = fillAluno();
        ler_materia->V[i] = *temp;  // copia conteúdo
        free(temp);
    }

    // Inicializa médias com 0
    for (int i = 0; i < 5; i++){
        ler_materia->media[i] = 0.0f;
    }

    return ler_materia;
}
