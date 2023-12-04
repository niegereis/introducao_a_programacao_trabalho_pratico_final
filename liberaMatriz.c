#include <stdlib.h>
#include "./funcoesDeMatrizes.h"

void liberaMatriz(int **matriz, int linhas){
    for(int i = 0; i < linhas; i++){
        free(matriz[i]);
    }
    free(matriz);
}