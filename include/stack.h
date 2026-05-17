#ifndef STACK_H
#define STACK_H

#include "quests.h"

/*BIBLIOTECA QUE FAZ UM OBJETO DO TIPO BARALHO SE COMPORTAR COMO UMA PILHA E REALIZAR OPERAÇÕES DE UMA PILHA*/

typedef tp_baralho tp_pilha;
typedef tp_pergunta tp_item_pergunta;

void inicializa_pilha(tp_pilha *p);

int pilha_vazia(tp_pilha *p);

int pilha_cheia(tp_pilha *p);

int push(tp_pilha *p, tp_item_pergunta e);

int pop(tp_pilha *p, tp_item_pergunta *e);

int top(tp_pilha *p, tp_item_pergunta *e);

void imprime_pilha(tp_pilha p);

int altura_pilha(tp_pilha *p);

#endif
