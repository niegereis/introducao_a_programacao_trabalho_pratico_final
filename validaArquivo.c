#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "./funcoesDeMatrizes.h"
#include "./constantes.h"
#include "./cores.h"

void validaArquivo(char *nomeArquivo, char *textoEntrada, char *textoErro){
    printf("\n" MAGENTA("%s"), textoEntrada);
    fgets(nomeArquivo, NOMEARQUIVO, stdin);
    int tamanhoNomeArquivo = strlen(nomeArquivo);
    nomeArquivo[tamanhoNomeArquivo - 1] = '\0';
    tamanhoNomeArquivo = strlen(nomeArquivo);
    while ((strcmp(nomeArquivo + tamanhoNomeArquivo - 4, ".txt") != 0)){
        printf("\n" RED("%s"), textoErro);
        fgets(nomeArquivo, NOMEARQUIVO, stdin);
        tamanhoNomeArquivo = strlen(nomeArquivo);
        nomeArquivo[tamanhoNomeArquivo - 1] = '\0';
        tamanhoNomeArquivo = strlen(nomeArquivo);
    }
}