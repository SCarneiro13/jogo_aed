#ifndef ACAO_H
#define ACAO_H

#include <stdio.h>
#include <stdlib.h>

#include "user.h"
#include "queue.h"
#include "listade.h"

void mostrarPosicoes(tp_jogador *jogadorAtual, tp_fila *fila);
void mostrarProximasCasas(tp_jogador *jogador, tp_listade *tabuleiro);
void mostrarPontos(tp_jogador *jogadorAtual, tp_fila *fila);
int menuDeAcao(tp_jogador *jogador, tp_fila *fila, tp_listade *tabuleiro);

void perdeu_turno(tp_jogador *jogador);

void mostrar_dado(int numero);

void venceu_jogo(tp_jogador *jogador);

void casa_normal();

void final_de_jogo();

#endif