#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./funcoesDeMatrizes.h"


int preencheMatrizAletoriamente(int **matriz, int linha, int coluna, char dificuldade){
    
    int valido = 0, matrizPossivel = 0;
    //Esquanto a matriz não for resolvível ele tenta gerar uma matriz novamente, até que seja gerada uma matriz resolvível
    while(!matrizPossivel){
        //Inicializa matriz zerando todas as sua posições
        for(int i = 0; i < linha; i++){
            for (int j = 0; j < coluna; j++){
                matriz[i][j] = 0;
            }
        }

        for(int i = 0; i < 12; i++){
            valido = 0;
            while(!valido){
                //Gera uma linha e uma coluna aleatória e verifica se já existe um número nessa posição
                //Se o número existir, ele volta até gerar uma linha e coluna que não tem valor na posição
                int linhaAtual = rand () % 9, colunaAtual = rand () % 9;
                if(matriz[linhaAtual][colunaAtual] != 0){
                    valido = 0;
                    continue;
                }
                //Gera um valor aleatório, verifica se ele poderá preenche a posição linha e coluna gerada
                //Se a função retornar 1, matriz na posição[linhaAtual][colunaAtual] pode receber o valor gerado
                //Se a função retornar 0, matriz na posição[linhaAtual][colunaAtual] não pode receber o valor gerado e valido recebe 0, e tenta gerar um novo item válido
                int valorAleatorio = rand () % 9 + 1;
                int lugarSeguro = verificaSeCelulaSegura(matriz, linhaAtual, colunaAtual, valorAleatorio);
                if(lugarSeguro == 1){
                    valido = 1;
                    matriz[linhaAtual][colunaAtual] = valorAleatorio;
                }
                else{
                    valido = 0;
                }
            }
        }
        //Se a matriz for resolvível a função retorna 1, ele sai do loop com a matriz preenchida corretamente
        if(resolverMatriz(matriz) == 1){
            matrizPossivel = 1;
        }
    }

    for(int regiao = 0; regiao < 9; regiao++){
        //Gera quantas peças vão ser retiradas do tabuleiro, em uma região
        //Nível fácil, são retiradas de 3 a 5 peças
        //Nível difívil, são retiradas de 6 a 8 peças
        int retiraFacil = rand () % 3 + 3, retiraDificil = rand () % 3 + 6, retira;
        if(dificuldade == 'F'){
            retira = retiraFacil;
        }
        else{
            retira = retiraDificil;
        }
        int podeRemover = 0;
        for(int j = retira; j > 0; j--){
            podeRemover = 0;
            //Enquando não conseguir remover uma peça ele tenta de novo, garantindo que sempre que o contador for subtraído uma peça será removida
            while(!podeRemover){
                //Gera uma linha e coluna para uma região que vai de 0 a 2
                int linhaRegiao = rand () % 3, colunaRegiao = rand () % 3;
                //Converte uma região indo de 0 a 8, em duas posições[x,y], sendo essas a posição [x,y] a esquerda em cima da região 3x3 
                int comecoDaRegiaoLinha = floor((regiao) / 3) * 3;
                int comecoDaRegiaoColuna = floor((regiao) % 3) * 3;
                //Verifica se na posição linha e coluna tem algum numero diferente de 0
                //Se tiver um número, ele recebe 0 no lugar do número anterior, e podeRemover recebe 1
                if(matriz[linhaRegiao + comecoDaRegiaoLinha][colunaRegiao + comecoDaRegiaoColuna] != 0){
                    matriz[linhaRegiao + comecoDaRegiaoLinha][colunaRegiao + comecoDaRegiaoColuna] = 0;
                    podeRemover = 1;
                }
            }
        }
    }

    return 0;
}
