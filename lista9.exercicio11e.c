int main() {
    int n;
    printf("Digite o número de alunos: ");
    scanf("%d", &n);

    Materia *curso = fillMateria(n);

    mediaMateria(curso);

    mostraMateria(curso);

    // Liberar memória
    for (int i = 0; i < curso->nAlunos; i++) {
        free(curso->V[i].vNotas);
    }
    free(curso->V);
    free(curso);

    return 0;
}
