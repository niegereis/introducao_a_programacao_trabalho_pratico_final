#include <stdio.h>
#include <stdlib.h>
#include "./funcoesDeMatrizes.h"
#include "./cores.h"

int leArquivo(int **matriz, int linhas, int colunas, char *nomeDoArquivo){
    
    FILE *sudoku;
    sudoku = fopen(nomeDoArquivo, "r");

    if(sudoku == NULL) {
      printf("\n" RED("Erro ao abrir o arquivo. Não existe jogo salvo em %s\n"), nomeDoArquivo);
      return 0;
    }
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            fscanf(sudoku,"%d", &matriz[i][j]);
        }
    }
    return 1;
}


