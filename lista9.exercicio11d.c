void mostraMateria(Materia *m1) {
    printf("Alunos e suas notas:\n");
    for (int i = 0; i < m1->nAlunos; i++) {
        printf("Matricula: %d\n", m1->V[i].matricula);
        printf("Nome: %s\n", m1->V[i].nome);
        printf("Notas: ");
        for (int j = 0; j < 5; j++) {
            printf("%.2f ", m1->V[i].vNotas[j]);
        }
        printf("\n\n");
    }

    printf("Médias das provas:\n");
    for (int i = 0; i < 5; i++) {
        printf("Prova %d: %.2f\n", i+1, m1->media[i]);
    }
}
