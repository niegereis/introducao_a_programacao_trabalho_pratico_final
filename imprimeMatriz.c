#include <stdio.h>
#include <stdlib.h>
#include "./funcoesDeMatrizes.h"
#include "./cores.h"

void imprimeMatriz(int **matriz, int linhas, int colunas){
    printf("\n");
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            if((i == 3 || i == 6) && j == 0){
                if((i == 3 || i == 6) && (j == 3 || j == 6)){
                    continue;
                }
                for (int i = 0; i < ((linhas * 2) + 6); i++){
                    if((i == 7 || i == 16) /*&& (j == 3 || j == 6)*/){
                        printf(BLUE(TAB_MJ));
                    }
                    else{
                        printf(BLUE(TAB_HOR));
                    }
                }
                printf("\n");
            }
            if(j == 3 || j == 6){
                printf(" ");
                printf( BLUE(TAB_VER) );
                printf(" ");
            }
            if(matriz[i][j] == 0){
                printf("- ");
            }
            else{
                printf("%d ", matriz[i][j]);
            }
        }
        printf("\n");
    }
}