#include <stdio.h>
#include "stack.h"

void inicializa_pilha(tp_baralho2 *p){
	p->topo = -1;
}

int pilha_vazia(tp_baralho2 *p){
	if(p->topo == -1){return 1;}
	return 0;
}

int pilha_cheia(tp_baralho2 *p){
	if(p->topo == MAX-1){return 1;}
	return 0;
}

int push(tp_baralho2 *p, tp_pergunta e){
	if(pilha_cheia(p) == 1){return 0;}
	p->topo++;
	p->item[p->topo] = e;
	return 1;
}

int pop(tp_baralho2 *p, tp_pergunta *e){
	if(pilha_vazia(p)){return 0;}
	*e = p->item[p->topo];
	p->topo--;
	return 1;
}

int top(tp_baralho2 *p, tp_pergunta *e){
	if(pilha_vazia(p)){return 0;}
	*e = p->item[p->topo];
	return 1;
}

void imprime_pilha(tp_baralho2 p){
	tp_pergunta e;
	printf("\n");
	while(!pilha_vazia(&p)){
		pop(&p, &e);
		printf("%d\n", e);
	}
}

int altura_pilha(tp_baralho2 *p){
	return p->topo + 1;
}