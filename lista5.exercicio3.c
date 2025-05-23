int funcao(char cadeia[21],char caracter){
    int ocorrencia=0;
        for (int i=0;cadeia[i]!='\0';i++){
            if (cadeia[i]== caracter){
                ocorrencia++;
            }
        }
    return ocorrencia;
}