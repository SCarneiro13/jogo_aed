#ifndef QUEUE_H
#define QUEUE_H

// Biblioteca de fila para usar com o baralho

#include "quests.h"
#define TRUE 1
#define FALSE 0

void inicializa_fila(tp_baralho *f);

int fila_vazia(tp_baralho *f);

int proximo(int pos);

int fila_cheia(tp_baralho *f);

int insere_fila(tp_baralho *f, tp_pergunta e);

int remove_fila(tp_baralho *f, tp_pergunta *e);

void imprime_fila(tp_baralho f);

int tamanho_fila1(tp_baralho *f);

int tamanho_fila2(tp_baralho f);

#endif