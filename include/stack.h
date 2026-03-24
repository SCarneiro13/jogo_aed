#ifndef STACK_H
#define STACK_H

// Biblioteca de pilha para usar com o baralho

#include "quests.h"
#define TRUE 1
#define FALSE 0
	
typedef struct{
	int topo;
	tp_pergunta item[MAX];
} tp_baralho2;

void inicializa_pilha(tp_baralho2 *p);

int pilha_vazia(tp_baralho2 *p);

int pilha_cheia(tp_baralho2 *p);

int push(tp_baralho2 *p, tp_pergunta e);

int pop(tp_baralho2 *p, tp_pergunta *e);

int top(tp_baralho2 *p, tp_pergunta *e);

void imprime_pilha(tp_pergunta p);

int altura_pilha(tp_baralho2 *p);

#endif