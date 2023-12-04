#include <stdio.h>
#include <math.h>
#include "./funcoesDeMatrizes.h"

int verificaCelula(int **matriz, int linha, int coluna, int regiao){
    
    int comecoDaRegiaoLinha = floor((regiao) / 3) * 3;
    int comecoDaRegiaoColuna = floor((regiao) % 3) * 3;
    if(matriz[linha + comecoDaRegiaoLinha][coluna + comecoDaRegiaoColuna] != 0){
        return matriz[linha + comecoDaRegiaoLinha][coluna + comecoDaRegiaoColuna];
    }
    return 0;
}