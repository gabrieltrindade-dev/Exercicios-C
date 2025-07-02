Livro * maiorBiblioteca(Biblioteca *b1, int numLivros){
    Livro *maior = b1->V[0];
    for (int i = 1; i < numLivros; i++){
        if (b1->V[i]->nVolume > maior->nVolume){
            maior = b1->V[i];
        }
    }
    return maior;
}
