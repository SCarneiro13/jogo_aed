#ifndef PUNICAO_H
#define PUNICAO_H

#include <stdio.h>
#include "user.h"
#include "tabuleiro.h"

// Definição das constantes para os tipos de punição
#define SEM_PUNICAO         0
#define VOLTAR_CASAS        1
#define PERDER_TURNO        2
#define REINICIAR_UNIDADE   3

/**
 * Declaração/Protótipo da função de punição.
 * A implementação real está no arquivo punicao.c
 */
void aplicar_punicao(tp_jogador *j, int id_punicao, tp_listade *tabuleiro);
int sortear_punicao();

#endif // PUNICAO_H
