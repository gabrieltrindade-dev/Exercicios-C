void imprime(Assalariados ** ptr, int numAssalariados){
    for(int i=0; i<numAssalariados; i++){
        printf("Nome da pessoa: %s\n", ptr[i]->nome);
        printf("Idade: %d\n", ptr[i]->idade);
        printf("Sexo: %c\n", ptr[i]->sexo);
        printf("Salario: %.2f\n", ptr[i]->salario);
        printf("Estado: %s\n", ptr[i]->estado);
    }
}