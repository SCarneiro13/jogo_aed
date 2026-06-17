#ifndef VENCEDOR_H
#define VENCEDOR_H

#include "tabuleiro.h"
#include "user.h" // Inclui a struct tp_jogador

/* * Verifica se o jogador atual alcançou ou passou da última casa do tabuleiro.
 * Retorna 1 (verdadeiro) se ele venceu, e 0 (falso) caso contrário.
 */
int verificar_vencedor(tp_jogador *jogador, tp_listade *tabuleiro);

#endif // VENCEDOR_H
