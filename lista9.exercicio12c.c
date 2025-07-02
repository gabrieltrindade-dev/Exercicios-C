void valorBiblioteca(Biblioteca *b1, int numLivros){
    float total = 0.0;
    for (int i = 0; i < numLivros; i++){
        total += b1->V[i]->preco * b1->V[i]->nVolume;
    }
    printf("Montante total da biblioteca: R$ %.2f\n", total);
}
