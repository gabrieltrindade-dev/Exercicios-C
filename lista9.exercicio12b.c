Biblioteca * fillBiblioteca(int numLivros){
    Biblioteca* nova_biblioteca = (Biblioteca*)malloc(sizeof(Biblioteca));
    nova_biblioteca->V = (Livro**)malloc(numLivros * sizeof(Livro*));
    if (nova_biblioteca == NULL || nova_biblioteca->V == NULL){
        printf("memoria insuficiente\n");
        exit(1);
    }
    nova_biblioteca->nLivros = numLivros;
    for (int i = 0; i < numLivros; i++){
        Livro* temp = fillLivro();
        nova_biblioteca->V[i] = temp;
    }
    return nova_biblioteca;
}
