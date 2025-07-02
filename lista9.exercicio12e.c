int main(){
    int n;
    printf("Digite o numero de livros na biblioteca: ");
    scanf("%d", &n);
    Biblioteca *b = fillBiblioteca(n);
    valorBiblioteca(b, n);

    Livro *mais_exemplares = maiorBiblioteca(b, n);
    printf("\nLivro com mais exemplares:\n");
    printf("Titulo: %s\n", mais_exemplares->titulo);
    printf("Autor: %s\n", mais_exemplares->autor);
    printf("Ano: %d\n", mais_exemplares->ano);
    printf("Exemplares: %d\n", mais_exemplares->nVolume);
    printf("Preco: R$ %.2f\n", mais_exemplares->preco);

    // Liberação de memória
    for (int i = 0; i < b->nLivros; i++) {
        free(b->V[i]);
    }
    free(b->V);
    free(b);

    return 0;
}
