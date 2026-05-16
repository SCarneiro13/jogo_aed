#ifndef SPACE_H
#define SPACE_H

typedef struct{
    int posicao; // A posição da casa no tabuleiro (primeira, segunda, terceira).
    int tipo; // Tipo da casa -> Normal = 0; Especial = 1; Pergunta = 2.
    int unidade; // A unidade da casa (primeira unidade, segunda unidade, terceira unidade).
}tp_space;


#endif