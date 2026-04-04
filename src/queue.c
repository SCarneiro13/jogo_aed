#include "queue.h"

void inicializaFila(tp_fila *f){
    f->ini = f->fim = MAX_FILA-1;
}

int filaVazia(tp_fila *f){
    if(f->ini == f->fim) return 1;
    return 0;
}

int proximo(int pos){
    if (pos == MAX_FILA-1) return 0;
    return ++pos;
}

int filaCheia(tp_fila *f){
    if(proximo(f->fim) == f->ini) return 1;
    return 0; 
}

int insereFila(tp_fila *f, tp_jogador e){
    if(filaCheia(f)) return 0;
    f->fim = proximo(f->fim);
    f->item[f->fim] = e;
    return 1;
}

int removeFila(tp_fila *f, tp_jogador *e){
    if(filaVazia(f)) return 0;
    f->ini = proximo(f->ini);
    *e = f->item[f->ini];
    return 1;
}