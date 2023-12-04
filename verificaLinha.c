#include <stdio.h>
#include "./funcoesDeMatrizes.h"
#include "./constantes.h"


int verificaLinha(int **matriz, int linha, int numeroEscolhido){
    
    for(int i = 0; i < TAMMATRIZ; i++){
        if(matriz[linha][i] == numeroEscolhido){
            int ondeColunaComNumeroIgualEsta = i + 1;
            return ondeColunaComNumeroIgualEsta;
        }
    }
    return 0;
}