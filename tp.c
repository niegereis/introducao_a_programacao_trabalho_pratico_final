#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "./funcoesDeMatrizes.h"
#include "./constantes.h"
#include "./cores.h"

int main(){

    srand(time(NULL));
    int num, linhas = TAMMATRIZ, colunas = TAMMATRIZ;
    char arquivoEscolhidoPeloUsuario[NOMEARQUIVO], nivelDificuldade;
    //Cria uma cópia da matriz para descobrir se o jogo é resolvível
    int **copiaMatriz = criaMatriz(linhas, colunas);
    //Matriz que fica o tabuleiro do jogo sodoku principal
    int **sudoku = criaMatriz(linhas, colunas);
    
    do{
        // Usuário escolhe opção do que quer fazer no jogo
        printf("\n"YELLOW("0 Sair do jogo\n1 Gerar novo jogo\n2 Carregar jogo\n3 Resolver jogo")"\n");
        printf("\n" YELLOW("Digite sua opção: "));
        scanf("%d", &num);
        while (!(num >= 0 && num <= 3)){
            printf("\n" RED("Opção inválida, digite uma opção válida: "));
            scanf("%d", &num);
        }
        

        // Swich lê opção escolhida pelo usuário
        switch (num){

        case 0:
            printf("\n" GREEN("Tchau!!!") "\n");
            liberaMatriz(sudoku, linhas);
            liberaMatriz(copiaMatriz, linhas);
            return 0;

        case 1:
            printf("\n" MAGENTA("Escolha o nível de dificuldade, digite F para fácil ou D para difícil: "));
            scanf(" %c", &nivelDificuldade);
            while (nivelDificuldade != 'F' && nivelDificuldade != 'D' && nivelDificuldade != 'f' && nivelDificuldade != 'd'){
                printf("\n" RED("Escolha um nível de dificuldade válido, digite F para fácil ou D para difícil: "));
                scanf(" %c", &nivelDificuldade);
            }
            limpaBuffer();
            preencheMatrizAletoriamente(sudoku, linhas, colunas, nivelDificuldade);
            imprimeMatriz(sudoku, linhas, colunas);
            break;

        case 2:
            limpaBuffer();
            int valido = 0;
            do {
            validaArquivo(arquivoEscolhidoPeloUsuario, "Indique o arquivo texto contendo o jogo: ", "Arquivo inválido! Indique um arquivo texto válido contendo o jogo: ");
            valido = leArquivo(sudoku, linhas, colunas, arquivoEscolhidoPeloUsuario);
            } while(!valido);
            imprimeMatriz(sudoku, linhas, colunas);
            break;

        case 3:
            resolverMatriz(sudoku);
            imprimeMatriz(sudoku, linhas, colunas);
            liberaMatriz(sudoku, linhas);
            liberaMatriz(copiaMatriz, linhas);
            return 0;
        }
       
        RegiaoMatriz comandoEscolhido;
        int ganhou = 0;
        
        while (!ganhou){

            leComando(comandoEscolhido.comando);
        
            if (strcmp(comandoEscolhido.comando, "salvar") == 0){
                char nomeDoArquivoOndeVaiSalvarJogo[NOMEARQUIVO];
                validaArquivo(nomeDoArquivoOndeVaiSalvarJogo, "Digite o nome do arquivo onde vai salvar o jogo: " , "Arquivo inválido! Indique um arquivo texto válido para salvar o jogo: ");
                salvaJogo(sudoku, nomeDoArquivoOndeVaiSalvarJogo);
                continue;
            }
            else if (strcmp(comandoEscolhido.comando, "voltar") == 0){
                break;
            }
            else{
                comandoEscolhido.regiao = comandoEscolhido.comando[0] - '0';
                comandoEscolhido.linha = comandoEscolhido.comando[1] - '0';
                comandoEscolhido.coluna = comandoEscolhido.comando[2] - '0';
                comandoEscolhido.preencheNumero = comandoEscolhido.comando[3] - '0';
            }
            int linhaConvertidaParaMatriz9x9 = (comandoEscolhido.linha - 1) + (floor((comandoEscolhido.regiao - 1) / 3) * 3);
            int colunaConvertidaParaMatriz9x9 = (comandoEscolhido.coluna - 1) + (((comandoEscolhido.regiao - 1) % 3) * 3);

            int colunaComErro = verificaLinha(sudoku, linhaConvertidaParaMatriz9x9, comandoEscolhido.preencheNumero);
            if (colunaComErro != 0){
                printf(RED("Erro! A coluna %d já possui o valor %d.\n"), colunaComErro, comandoEscolhido.preencheNumero);
            }

            int linhaComErro = verificaColuna(sudoku, colunaConvertidaParaMatriz9x9, comandoEscolhido.preencheNumero);
            if (linhaComErro != 0){
                printf(RED("Erro! A linha %d já possui o valor %d.\n"), linhaComErro, comandoEscolhido.preencheNumero);
            }

            int regiaoComErro = verificaRegiao(sudoku, comandoEscolhido.regiao - 1, comandoEscolhido.preencheNumero);
            if (regiaoComErro != 0){
                printf(RED("Erro! A regiao %d já possui o valor %d.\n"), regiaoComErro, comandoEscolhido.preencheNumero);
            }

            int valorAtualNaPosicaoPreenchido = verificaCelula(sudoku, comandoEscolhido.linha - 1, comandoEscolhido.coluna - 1, comandoEscolhido.regiao - 1);
            if (valorAtualNaPosicaoPreenchido != 0){
                printf(RED("Erro! A regiao %d(%d,%d) já possui o valor %d.\n"), comandoEscolhido.regiao, comandoEscolhido.linha, comandoEscolhido.coluna, comandoEscolhido.preencheNumero);
            }

            if (colunaComErro == 0 && linhaComErro == 0 && regiaoComErro == 0 && valorAtualNaPosicaoPreenchido == 0){
                int comecoDaRegiaoLinha = floor((comandoEscolhido.regiao - 1) / 3) * 3;
                int comecoDaRegiaoColuna = floor((comandoEscolhido.regiao - 1) % 3) * 3;
                sudoku[comecoDaRegiaoLinha + comandoEscolhido.linha - 1][comecoDaRegiaoColuna + comandoEscolhido.coluna - 1] = comandoEscolhido.preencheNumero;
            }
            ganhou = verificaSeGanhou(sudoku, linhas, colunas);
            for (int i = 0; i < TAMMATRIZ; i++){
                for (int j = 0; j < TAMMATRIZ; j++){
                    copiaMatriz[i][j] = sudoku[i][j];
                }
            }
            if(!(resolverMatriz(copiaMatriz))){
                printf("\n" RED("Você perdeu! Sudoku sem resolução!\n"));
                liberaMatriz(sudoku, linhas);
                liberaMatriz(copiaMatriz, linhas);
                return 0;
            }
            imprimeMatriz(sudoku, linhas, colunas);
            if (ganhou == 1){
                printf("\n" GREEN("Parabéns! Você ganhou!\n"));
            }
        }

    } while (1);

}