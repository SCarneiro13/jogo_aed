#include <stdio.h>
#include "movimentacao.h"

void moverJogador(tp_jogador *j, int casas){

    j->posicao += casas;

    printf("%s avançou %d casas!\n", j->nome, casas);
    printf("Posição atual: %d\n", j->posicao);
}
