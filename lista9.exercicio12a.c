Livro * fillLivro(){
    Livro* novo_livro = malloc(sizeof(Livro));
    if(novo_livro == NULL){
        printf("memoria insuficiente\n");
        exit(1);
    }
    printf("digite o ano do livro\n");
    scanf(" %d", &novo_livro->ano);
    printf("digite o titulo\n");
    scanf(" %99s", novo_livro->titulo);
    printf("digite o autor\n");
    scanf(" %99s", novo_livro->autor);
    printf("digite o numero de exemplares\n");
    scanf(" %d", &novo_livro->nVolume);
    printf("digite o preco\n");
    scanf(" %f", &novo_livro->preco);
    return novo_livro;
}
