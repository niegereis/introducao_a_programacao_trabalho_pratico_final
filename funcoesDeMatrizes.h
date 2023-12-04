#ifndef FUNCOES_DE_MATRIZES_H
#define FUNCOES_DE_MATRIZES_H
#include "./constantes.h"

typedef struct{
    char comando[NOMEARQUIVO];
    int regiao, linha, coluna, preencheNumero;
} RegiaoMatriz;

typedef struct {
  int linha;
  int coluna;
  int valor;
} Movimento;

//Cria uma matriz alocando dinâmicamente suas linhas x colunas
int **criaMatriz(int linhas, int colunas);

//Imprime uma matriz em formato de sudoku
void imprimeMatriz(int **matriz, int linhas, int colunas);

//Lê um arquivo digitado pelo usuário que contém um jogo sudoku salvo, retorna 0 se o arquivo não não existir e retorna 1 quando o usuário digita um arquivo válido
int leArquivo(int **matriz, int linhas, int colunas, char *nomeDoArquivo);

//Limpa o "\n" do buffer, para quando usuário precisar digitar um texto com fgets, não ler o "\n" que ficou de outra leitura
void limpaBuffer();

//Verifica em uma linha se o número escolhido já se encontra em alguma posição, e se estiver retorna a coluna na qual ele foi encontrado
int verificaLinha(int **matriz, int linha, int numeroEscolhido);

//Verifica em uma coluna se o número escolhido já se encontra em alguma posição, e se estiver retorna a linha na qual ele foi encontrado
int verificaColuna(int **matriz, int coluna, int numeroEscolhido);

//Verifica na região se o número escolhido já se encontra em alguma posição, e se estiver retorna a região na qual ele foi encontrado
int verificaRegiao(int **matriz, int regiaoEscolhida , int numeroEscolhido);

//Verifica em uma posição[linha,coluna] se um número já se encontra lá, e se estiver retorna o número que foi encontrado
int verificaCelula(int **matriz, int linha, int coluna, int regiao);

//Verifica se o usuário já preencheu todas posições do sudoku, retorna 0 caso alguma posição ainda não tenha sido preenchida e retorna 1 caso todas posições tenham sido preenchidas 
int verificaSeGanhou(int **matriz, int linhas, int colunas);

//Salva o jogo que o usuáro começou a jogar em um arquivo
void salvaJogo(int **matriz, char nomeDoArquivo[256]);

//Resolve a matriz
int resolverMatriz(int **matriz);

//Verifica se é possível colocar um número, retornando 0 caso o número já esteja na linha, coluna ou região e retornando 1 caso seja possível colocar um número naquela posição
int verificaSeCelulaSegura(int **matriz, int linha, int coluna, int numeroEscolhido);

//Preenche uma matriz aleatoriamente 
int preencheMatrizAletoriamente(int **matriz, int linha, int coluna, char dificuldade);

//Recebe o comando digitado pelo usuário e salva na variável comando
void leComando(char *comando);

//Libera a memória alocada para matriz
void liberaMatriz(int **matriz, int linhas);

//Valida se arquivo é .txt ou não
void validaArquivo(char *nomeArquivo, char *textoEntrada, char *textoErro);

#endif