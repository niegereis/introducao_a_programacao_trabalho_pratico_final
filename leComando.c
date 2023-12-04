#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "./funcoesDeMatrizes.h"
#include "./constantes.h"
#include "./cores.h"

//Valida se o comando é válido, se for retorna 1, se não for retorna 0
int verificaComando(char *comando, int tamComando){
    int numeroValido = (tamComando == 4 && isdigit(comando[0]) != 0 && isdigit(comando[1]) != 0 && isdigit(comando[2]) != 0 && isdigit(comando[3]) != 0); 
    int digito1 = comando [0] - '0';
    int digito2 = comando [1] - '0';
    int digito3 = comando [2] - '0';
    int digito4 = comando [3] - '0';
    int intervaloValido = digito1 >= 1 && digito1 <= 9 && digito2 >= 1 && digito2 <= 3 && digito3 >= 1 && digito3 <= 3 && digito4 >= 1 && digito4 <= 9;
    if(intervaloValido && numeroValido){
        return 1;
    }
    else{
        return 0;
    }
}

//
void leComando(char *comando){

    printf("\n" MAGENTA("Digite um comando ou indique a celula a alterar: "));
    fgets(comando, NOMEARQUIVO, stdin);
    int tamComando = strlen(comando);
    comando[tamComando - 1] = '\0';
    tamComando = strlen(comando);
    //Percorre uma string e para cada letra maiúscula troca por uma minúscula
    for(int i = 0; i < tamComando; i++){
        //tolower recebe um int(char) e devolve o char minusculo
        comando[i] = tolower(comando[i]); 
    }
    
    //Valida se o comando passado é uma string válida ou um comando numérico válido
    //Se não for, pede ao usuário que digite um novo comando
    while (!(strcmp(comando, "salvar") == 0 || strcmp(comando, "voltar") == 0 || verificaComando(comando, tamComando))){
        printf("\n" RED("Erro! Digite um comando válido ou indique a celula a alterar: "));
        fgets(comando, NOMEARQUIVO, stdin);
        tamComando = strlen(comando);
        comando[tamComando - 1] = '\0';
        tamComando = strlen(comando);
        for(int i = 0; i < tamComando; i++){
            comando[i] = tolower(comando[i]);
        } 
        
    }
    
}
