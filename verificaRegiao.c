#include <stdio.h>
#include <math.h>
#include "./funcoesDeMatrizes.h"

int verificaRegiao(int **matriz, int regiaoEscolhida , int numeroEscolhido){
    
    int comecoDaRegiaoLinha = floor((regiaoEscolhida) / 3) * 3;
    int comecoDaRegiaoColuna = floor((regiaoEscolhida) % 3) * 3;
    int tamRegiao = 3;
    
    for(int i = comecoDaRegiaoLinha; i < comecoDaRegiaoLinha + tamRegiao; i++){
        for(int j = comecoDaRegiaoColuna; j < comecoDaRegiaoColuna + tamRegiao; j++){
            if(matriz[i][j] == numeroEscolhido){
                return regiaoEscolhida + 1;
            }
        }
    }
    
    return 0;
}