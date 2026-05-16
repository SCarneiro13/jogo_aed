#ifndef LISTADE_H
#define LISTADE_H
#include <stdio.h>
#include <stdlib.h>
#include "space.h"

typedef tp_space tp_item;

// a lista principal nao aponta diretamente para o primeiro no
// a lista aponta para a struct descritor e o descritor aponta para o primeiro no
typedef struct tp_no_aux{
    struct tp_no_aux *ant;
    tp_item info;
    struct tp_no_aux *prox;
} tp_no;

// struct descritor ou cabeçalho
typedef struct{
    tp_no *ini;
    tp_no *fim;
}tp_listade;

tp_listade *inicializaListade (){
    tp_listade *lista = (tp_listade *) malloc (sizeof(tp_listade));
    lista->ini = NULL;
    lista->fim = NULL;
    
    return lista;
}

int listadeVazia (tp_listade *lista){
    if(lista->ini == NULL) return 1; // para estar vazia so precisa verificar ou o ini ou o fim (se um for NULL o outro tbm é NULL)
    return 0;
}

tp_no *aloca(){
    tp_no *pt;
    pt = (tp_no *) malloc (sizeof(tp_no));
    return pt;
}

int insereListadeOrdem (tp_listade *l, tp_item e){
    tp_no *aux;
    tp_no *novo_no;
    novo_no = aloca();

    if(!novo_no) return 0;
    novo_no->info = e;

    if(listadeVazia(l)){
        novo_no->ant = NULL;
        novo_no->prox = NULL;
        l->ini =l->fim = novo_no;
    } else if(e.posicao <= l->ini->info.posicao){
        novo_no->ant = NULL;
        novo_no->prox = l->ini;
        l->ini->ant = novo_no;
        l->ini = novo_no;
    } else if (e.posicao >= l->fim->info.posicao){
        novo_no->ant = l->fim;
        novo_no->prox = NULL;
        l->fim->prox = novo_no;
        l->fim = novo_no;
    } else {
        aux = l->ini;
        while(aux != NULL && e.posicao > aux->info.posicao){
            aux = aux->prox;
        }

        novo_no->prox = aux;
        novo_no->ant = aux->ant;
        
        aux->ant->prox = novo_no;
        aux->ant = novo_no;
    }

    return 1;
}

tp_listade *destroiListade (tp_listade *lista){
    tp_no *atu;
    atu=lista->ini;
    while(atu!=NULL){
        lista->ini=atu->prox;
        free(atu);
        atu=lista->ini;
        }
    free(lista);
    return NULL;
}

#endif