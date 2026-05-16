#ifndef USER_H
#define USER_H

#include "space.h"

typedef struct{
    int dificil;
    int medio;
    int facil;
} tp_acertos;

typedef struct{
    char nick[30]; // Nome do usuario
    tp_space casaAtual;
    tp_acertos acertos;
    int erros;
} tp_jogador;

void cadastrarJogador(tp_jogador *j);
void inicializarJogador(tp_jogador *j);

#endif