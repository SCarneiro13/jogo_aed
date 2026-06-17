#include "vencedor.h"

int verificar_vencedor(tp_jogador *jogador, tp_listade *tabuleiro) {
    int linha_de_chegada = ultima_posicao(tabuleiro);

    // Proteção contra tabuleiro vazio
    if (linha_de_chegada == 0) {
        return 0; 
    }

    // Verifica se a posição da casa atual do jogador atingiu o fim
    if (jogador->casaAtual.posicao >= linha_de_chegada) {
        return 1; // Venceu
    }

    return 0; // Jogo continua
}
