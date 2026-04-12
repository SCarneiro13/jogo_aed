#ifndef QUEUE_H
#define QUEUE_H
#include "user.h"
#define MAX_FILA 5 // 5 posições porque uma é sacrificada

typedef struct {
	tp_jogador item[MAX_FILA]; // Cada posição do vetor/fila representa um jogador com suas informações
	int ini, fim;
} tp_fila;

void inicializaFila(tp_fila *f);
int filaVazia(tp_fila *f);
int proximo(int pos);
int filaCheia(tp_fila *f);
int insereFila(tp_fila *f, tp_jogador e);
int removeFila(tp_fila *f, tp_jogador *e);

#endif
