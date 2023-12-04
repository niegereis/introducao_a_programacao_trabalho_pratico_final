#include <stdio.h>
#include "./constantes.h"
#include "./funcoesDeMatrizes.h"

void salvaJogo(int **matriz, char nomeDoArquivo[256]){
    FILE *arquivo;
    arquivo = fopen(nomeDoArquivo, "w");
    for (int i = 0; i < TAMMATRIZ; i++){
        for (int j = 0; j < TAMMATRIZ; j++){
            fprintf(arquivo, "%d ", matriz[i][j]);    
        }   
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
}