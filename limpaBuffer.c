#include <stdio.h>
#include "./funcoesDeMatrizes.h"

void limpaBuffer(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}