void mostrar_aluno(char* nome_arquivo) {
    FILE* bin = fopen(nome_arquivo, "rb");
    if (bin == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    ALUNO aluno;
    printf("Alunos com média >= 6.0:\n");
    while (fread(&aluno, sizeof(ALUNO), 1, bin) == 1) {
        float media = (aluno.nota1 + aluno.nota2) / 2;
        if (media >= 6.0) {
            printf("%s\n", aluno.nome);
        }
    }

    fclose(bin);
}
