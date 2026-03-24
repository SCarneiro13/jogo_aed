#include <stdio.h>
#include "queue.h"

void inicializa_fila(tp_baralho *f){
	f->ini = f->fim = MAX-1;
}

int fila_vazia(tp_baralho *f){
	if(f->ini == f->fim){return TRUE;}
	
	return FALSE;
}

int proximo(int pos){
	if(pos == MAX-1) return 0;
	return ++pos;
}

int fila_cheia(tp_baralho *f){
	if(proximo(f->fim) == f->ini){return TRUE;}
	
	return FALSE;
}

int insere_fila(tp_baralho *f, tp_pergunta e){
	if(filaCheia(f)){return FALSE;}
	f->fim = proximo(f->fim);
	f->baralho[f->fim] = e;
	return TRUE;
}

int remove_fila(tp_baralho *f, tp_pergunta *e){
	if(filaVazia(f)){return FALSE;}
	
	f->ini = proximo(f->ini);
	*e = f->baralho[f->ini];
	
	return TRUE;
}

void imprime_fila(tp_baralho f){
	tp_pergunta e;
	while(!filaVazia(&f)){
		removeFila(&f, &e);
		printf("\n%c", e);
	}
}

int tamanho_fila1(tp_baralho *f){
	if(filaVazia(f)){return FALSE;}
	if(f->ini < f->fim){return f->fim - f->ini;}
	return MAX - 1 - f->ini + f->fim + 1;
}

int tamanho_fila2(tp_baralho f){
	int cont = 0;
	tp_pergunta e;
	while(!filaVazia(&f)){
		removeFila(&f, &e);
		cont++;
	}
	return cont;
}