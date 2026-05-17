#include <stdio.h>
#include "movimentacao.h"

void moverJogadorPara(tp_jogador *j, int posicao, tp_listade *tabuleiro){
    int limite = ultima_posicao(tabuleiro);

    if(posicao < 1) posicao = 1;
    if(limite > 0 && posicao > limite) posicao = limite;

    if(buscar_casa(tabuleiro, posicao, &j->casaAtual)){
        printf("Posicao atual de %s: %d\n", j->nick, j->casaAtual.posicao);
    }
}

void moverJogador(tp_jogador *j, int casas, tp_listade *tabuleiro){
    int nova_posicao = j->casaAtual.posicao + casas;

    moverJogadorPara(j, nova_posicao, tabuleiro);
}
