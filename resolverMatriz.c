#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "./constantes.h"
#include "./funcoesDeMatrizes.h"

// Verifica se posição está ou não preenchida, caso não esteja retorna 1, caso
// esteja retorna 0
int contemPosicaoNaoPreenchida(int **matriz) {
  for (int i = 0; i < TAMMATRIZ; i++) {
    for (int j = 0; j < TAMMATRIZ; j++) {
      if (matriz[i][j] == 0) {
        return 1;
      }
    }
  }
  return 0;
}

// Verifica se um numero pode preencher uma posição linha, coluna e região,
// retorna 0 se não pode e retorna 1 se puder preencher posição
int verificaSeCelulaSegura(int **matriz, int linha, int coluna,
                           int numeroEscolhido) {
  if (verificaLinha(matriz, linha, numeroEscolhido)) {
    return 0;
  }

  if (verificaColuna(matriz, coluna, numeroEscolhido)) {
    return 0;
  }

  int linhaDoComecoDaRegiao, colunaDoComecoDaRegiao;
  if (linha <= 2) {
    linhaDoComecoDaRegiao = 0;
  } else if (linha <= 5) {
    linhaDoComecoDaRegiao = 3;
  } else if (linha <= 8) {
    linhaDoComecoDaRegiao = 6;
  }
  if (coluna <= 2) {
    colunaDoComecoDaRegiao = 0;
  } else if (coluna <= 5) {
    colunaDoComecoDaRegiao = 3;
  } else if (coluna <= 8) {
    colunaDoComecoDaRegiao = 6;
  }

  for (int i = linhaDoComecoDaRegiao; i < linhaDoComecoDaRegiao + 3; i++) {
    for (int j = colunaDoComecoDaRegiao; j < colunaDoComecoDaRegiao + 3; j++) {
      if (matriz[i][j] == numeroEscolhido) {
        return 0;
      }
    }
  }
  return 1;
}

int resolverMatriz(int **tabuleiro) {
  Movimento movimentos[1000];
  int ultimoMovimento = 0;
  int linha = 0, coluna = 0;
  int comecarDe = 1, voltei = 0;
  // Percorre enquanto tiver posição não preenchida na matriz
  while (contemPosicaoNaoPreenchida(tabuleiro)) {
    // Se a posição atual já tiver um valor, ele pula pra próxima coluna ou se
    // coluna for igual a 8, ele pula pra próxima linha zerando a coluna Caso
    // esteja voltando uma posição ele não faz essa verificação
    int posicaoAtual = tabuleiro[linha][coluna];
    if (posicaoAtual != 0 && !voltei) {
      if (coluna == 8) {
        linha++;
        coluna = 0;
      } else {
        coluna++;
      }
      continue;
    }
    // Se a quantidade de movimentos for negativa significa que ele está
    // voltando mais do que deveria Então ele retorna 0(matriz sem solução)
    if (ultimoMovimento == -1) {
      return 0;
    }

    int colocouNumero = 0;
    // Verifica se é possível colocar um número na célula, caso seja possível
    // ele salva o movimento feito na variável movimentos Atualiza a quantidade
    // de movimentos na variável último movimento e move para próxima coluna ou
    // linha, caso coluna >= 9
    for (int i = comecarDe; i <= 9; i++) {
      if (verificaSeCelulaSegura(tabuleiro, linha, coluna, i)) {
        comecarDe = 1;
        voltei = 0;
        colocouNumero = 1;
        movimentos[ultimoMovimento].coluna = coluna;
        movimentos[ultimoMovimento].linha = linha;
        movimentos[ultimoMovimento].valor = i;
        ultimoMovimento++;
        tabuleiro[linha][coluna] = i;
        coluna++;
        if (coluna >= 9) {
          linha++;
          coluna = 0;
        }
        break;
      }
    }
    // Caso nenhum número de 1 a 9 seja colocado na célula, então atualiza a
    // linha e coluna para o último movimento feito Voltando uma posição e
    // tentando outro valor (backtraking)
    if (!colocouNumero) {
      voltei = 1;
      tabuleiro[linha][coluna] = 0;
      ultimoMovimento--;
      linha = movimentos[ultimoMovimento].linha;
      coluna = movimentos[ultimoMovimento].coluna;
      comecarDe = movimentos[ultimoMovimento].valor + 1;
    }
  }
  return 1;
}