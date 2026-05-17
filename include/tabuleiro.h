#ifndef TABULEIRO_H
#define TABULEIRO_H

#include "listade.h"

tp_listade *criar_caminho();
int buscar_casa(tp_listade *tabuleiro, int posicao, tp_space *casa);
int ultima_posicao(tp_listade *tabuleiro);

#endif
