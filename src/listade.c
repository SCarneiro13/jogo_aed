#include <stdio.h>
#include <stdlib.h>
#include "listade.h"

/* Inicializa a lista duplamente encadeada */
tp_listade *inicializaListade() {
    tp_listade *lista = (tp_listade *)malloc(sizeof(tp_listade));
    if (lista == NULL) {
        printf("Erro: falha ao alocar lista.\n");
        return NULL;
    }
    lista->ini = NULL;
    lista->fim = NULL;
    return lista;
}

/* Verifica se a lista esta vazia */
int listadeVazia(tp_listade *lista) {
    return (lista == NULL || lista->ini == NULL);
}

/* Aloca um novo no */
tp_no *aloca() {
    tp_no *novo = (tp_no *)malloc(sizeof(tp_no));
    if (novo == NULL) {
        printf("Erro: falha ao alocar no.\n");
        return NULL;
    }
    novo->ant  = NULL;
    novo->prox = NULL;
    return novo;
}

/* Insere em ordem crescente de posicao */
int insereListadeOrdem(tp_listade *l, tp_item e) {
    tp_no *novo = aloca();
    if (novo == NULL) return 0;

    novo->info = e;

    /* Lista vazia */
    if (listadeVazia(l)) {
        l->ini = novo;
        l->fim = novo;
        return 1;
    }

    /* Encontra posicao correta */
    tp_no *atual = l->ini;
    while (atual != NULL && atual->info.posicao < e.posicao) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        /* Inserir no final */
        novo->ant      = l->fim;
        l->fim->prox   = novo;
        l->fim         = novo;
    } else if (atual == l->ini) {
        /* Inserir no inicio */
        novo->prox     = l->ini;
        l->ini->ant    = novo;
        l->ini         = novo;
    } else {
        /* Inserir no meio */
        novo->ant          = atual->ant;
        novo->prox         = atual;
        atual->ant->prox   = novo;
        atual->ant         = novo;
    }

    return 1;
}

/* Destroi toda a lista e libera memoria */
tp_listade *destroiListade(tp_listade *lista) {
    if (lista == NULL) return NULL;

    tp_no *atual = lista->ini;
    while (atual != NULL) {
        tp_no *prox = atual->prox;
        free(atual);
        atual = prox;
    }

    free(lista);
    return NULL;
}