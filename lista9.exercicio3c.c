void relatorio(Assalariados ** ptr, int numAssalariados){
    for (int i = 0; i < 27; i++) {
        int contador = 0;

        for (int j = 0; j < numAssalariados; j++) {
            if (strcmp(ptr[j]->estado, estado[i]) == 0 &&
                ptr[j]->sexo == 'M' &&
                ptr[j]->idade > 40 &&
                ptr[j]->salario > 1000.0) {
                contador++;
            }
        }

        if (contador > 0) {
            printf("Estado=%s com %d homens maiores de 40 anos e salário maior que R$ 1000,00\n", estado[i], contador);
        }
    }
}