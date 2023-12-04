#include <stdlib.h>
#include "./funcoesDeMatrizes.h"


int** criaMatriz(int linhas, int colunas){
    int **matriz;
    matriz = malloc(linhas * sizeof (int *));
    for(int i = 0; i < linhas; i++){
        matriz[i] = calloc(colunas * sizeof (int), 1);
    }
    return matriz;
}

