#ifndef LISTADE_H
#define LISTADE_H

#include <stdio.h>
#include <stdlib.h>
#include "space.h"

typedef tp_space tp_item;

typedef struct tp_no_aux{
    struct tp_no_aux *ant;
    tp_item info;
    struct tp_no_aux *prox;
} tp_no;

typedef struct{
    tp_no *ini;
    tp_no *fim;
} tp_listade;

tp_listade *inicializaListade();
int listadeVazia(tp_listade *lista);
tp_no *aloca();
int insereListadeOrdem(tp_listade *l, tp_item e);
tp_listade *destroiListade(tp_listade *lista);

#endif
