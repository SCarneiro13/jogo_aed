#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H

#include "user.h"
#include "tabuleiro.h"

void moverJogador(tp_jogador *j, int casas, tp_listade *tabuleiro);
void moverJogadorPara(tp_jogador *j, int posicao, tp_listade *tabuleiro);

#endif
