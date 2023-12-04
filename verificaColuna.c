#include <stdio.h>
#include "./funcoesDeMatrizes.h"
#include "./constantes.h"

int verificaColuna(int **matriz, int coluna, int numeroEscolhido){
    
    for(int i = 0; i < TAMMATRIZ; i++){
        if(matriz[i][coluna] == numeroEscolhido){
            int ondeLinhaComNumeroIgualEsta = i + 1;
            return ondeLinhaComNumeroIgualEsta;
        }
    }
    return 0;
}
