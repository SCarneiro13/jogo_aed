#include <stdio.h>

#include "stack.h"

void inicializa_pilha(tp_pilha *p){
	p->topo = -1;
}

int pilha_vazia(tp_pilha *p){
	if(p->topo == -1){return 1;}
	return 0;
}

int pilha_cheia(tp_pilha *p){
	if(p->topo == (MAX_PERGUNTAS/3)-1){return 1;}
	return 0;
}

int push(tp_pilha *p, tp_item e){
	if(pilha_cheia(p) == 1){return 0;}
	p->topo++;
	p->pergunta[p->topo] = e;
	return 1;
}

int pop(tp_pilha *p, tp_item *e){
	if(pilha_vazia(p)){return 0;}
	*e = p->pergunta[p->topo];
	p->topo--;
	return 1;
}

int top(tp_pilha *p, tp_item *e){
	if(pilha_vazia(p)){return 0;}
	*e = p->pergunta[p->topo];
	return 1;
}

void imprime_pilha(tp_pilha p){
	tp_item e;
	printf("\n");
	while(!pilha_vazia(&p)){
		pop(&p, &e);
		printf("%s\n", e.pergunta);
	}
}

int altura_pilha(tp_pilha *p){
	return p->topo + 1;
}