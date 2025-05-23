#include <stdio.h>
int opiniao_otimo(char*opiniao){
    int otimo=0;
    for (int i=0;i<100;i++){
        if(opiniao[i]=='a'){
            otimo+=1;
        }
    }
    return otimo;
}

int dif_percentual(char*opiniao){
    int bom=0;
    int regular=0;
    for (int i=0;i<100;i++){
        if (opiniao[i]=='b'){
            bom+=1;
        }
        else if(opiniao[i]=='c'){
            regular+=1;
        }
    }
    int diferenca;
    float media=(bom+regular)/2.0;
    if (bom>regular){
        diferenca=100*(bom-regular)/media;
    }
    else if (regular>bom){
        diferenca=100*(regular-bom)/media;
    }
    else{
        return 0;
    }
    return diferenca;
}

float media_idade_ruim(int*idade,char*opiniao){
    float soma=0;
    int contador=0;
    for (int i = 0;i<100;i++){
        if (opiniao[i]=='d'){
            soma+=idade[i];
            contador++;
        }
    }
    if(contador==0){
        return 0;
    }
    else{
        return soma/contador;
    }
}

void func_pessimo(int*qnt,int*maior,float*dif,int*idade,char*opiniao){
    int maior_o=0;
    int maior_r=0;
    for (int i =0;i<100;i++){
        if (opiniao[i]=='e'){
            (*qnt)++;
            if (*maior<idade[i]){
                *maior=idade[i];
            }
        }
        if (opiniao[i]=='a'){
            if (maior_o<idade[i]){
                maior_o=idade[i];
            }
        }
        if (opiniao[i]=='d'){
            if (maior_r<idade[i]){
                maior_r=idade[i];
            }
        }

    }
    if (maior_o>maior_r){
        *dif=maior_o-maior_r;
    }
    else if (maior_r>maior_o){
        *dif=maior_r-maior_o;
    }
}

int main(){
    int idade[100];
    char opiniao[100];

    for (int i = 0;i<100;i++){
        printf("digite a sua idade");
        scanf(" %d",&idade[i]);
        printf("qual sua opinao a= otimo,b=bom,c=regular,d=ruim,e=pessimo");
        scanf(" %c",&opiniao[i]);

        }
    int qnt_pessimo;
    int maior_idade_pessimo;
    float dif_maior_otimo_ruim;


    int media1=opiniao_otimo(opiniao);
    int dif = dif_percentual(opiniao);
    int media2 = media_idade_ruim(idade,opiniao);
    func_pessimo(&qnt_pessimo,&maior_idade_pessimo,&dif_maior_otimo_ruim,idade,opiniao);

    printf("\nResultados:\n");
    printf("Quantidade de 'ótimo': %d\n", media1);
    printf("Diferença percentual entre 'bom' e 'regular': %d%%\n", dif);
    printf("Média de idade dos que responderam 'ruim': %.2f anos\n", media2);
    printf("Quantidade de 'péssimo': %d\n", qnt_pessimo);
    printf("Maior idade entre os que responderam 'péssimo': %d\n", maior_idade_pessimo);
    printf("Diferença entre maior idade 'ótimo' e 'ruim': %.2f anos\n", dif_maior_otimo_ruim);

    return 0;
}