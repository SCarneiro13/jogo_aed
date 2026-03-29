#ifndef STACK_H
#define STACK_H

#include "quests.h"

/*BIBLIOTECA QUE FAZ UM OBJETO DO TIPO BARALHO SE COMPORTAR COMO UMA PILHA E REALIZAR OPERAÇÕES DE UMA PILHA*/

#define tp_pilha tp_baralho
#define tp_item tp_pergunta

void inicializa_pilha(tp_pilha *p);

int pilha_vazia(tp_pilha *p);

int pilha_cheia(tp_pilha *p);

int push(tp_pilha *p, tp_item e);

int pop(tp_pilha *p, tp_item *e);

int top(tp_pilha *p, tp_item *e);

void imprime_pilha(tp_pilha p);

int altura_pilha(tp_pilha *p);

#endif