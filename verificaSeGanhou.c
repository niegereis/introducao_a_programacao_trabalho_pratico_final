#include <stdlib.h>
#include "./funcoesDeMatrizes.h"

int verificaSeGanhou(int **matriz, int linhas, int colunas){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            if(matriz[i][j] == 0){
                return 0;
            }
        }
    }
    return 1;
}
