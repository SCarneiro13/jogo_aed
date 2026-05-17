#include <stdlib.h>
#include "punicao.h"
#include "movimentacao.h"

int sortear_punicao(){
    return (rand() % 3) + 1;
}

void aplicar_punicao(tp_jogador *j, int id_punicao, tp_listade *tabuleiro) {
    switch (id_punicao) {
        case VOLTAR_CASAS:
            printf("[PUNICAO] %s voltou 2 casas.\n", j->nick);
            moverJogador(j, -2, tabuleiro);
            break;

        case PERDER_TURNO:
            printf("[PUNICAO] %s perdeu o proximo turno.\n", j->nick);
            j->perdeuTurno = 1;
            break;

        case REINICIAR_UNIDADE:
            printf("[PUNICAO]  %s voltou para o inicio desta unidade.\n", j->nick);
            if(j->casaAtual.unidade == 1) moverJogadorPara(j, 1, tabuleiro);
            else if(j->casaAtual.unidade == 2) moverJogadorPara(j, 16, tabuleiro);
            else moverJogadorPara(j, 31, tabuleiro);
            break;

        default:
            break;
    }
}
