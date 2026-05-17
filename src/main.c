#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "quests.h"
#include "stack.h"
#include "queue.h"
#include "user.h"
#include "baralho.h"
#include "criarJogadores.h"
#include "tabuleiro.h"
#include "movimentacao.h"
#include "punicao.h"

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    srand(time(NULL));

    tp_fila fila;
    inicializaFila(&fila);

    tp_listade *tabuleiro = criar_caminho();
    int fim_de_jogo = 0;

    tp_baralho pilha_unidade1, pilha_unidade2, pilha_unidade3;
    inicializa_pilha(&pilha_unidade1);
    inicializa_pilha(&pilha_unidade2);
    inicializa_pilha(&pilha_unidade3);

    int num_questions = 0;
    for(int i = 0; i < MAX_PERGUNTAS; i++) {
        if(baralho[i].unidade != 0) {
            num_questions++;
        }
    }
    embaralharPerguntas(baralho, num_questions, &pilha_unidade1, &pilha_unidade2, &pilha_unidade3);

    printf("BEM VINDO AO JOGO!\n\n");
    criarJogadores(&fila);

    while(!fim_de_jogo && (!pilha_vazia(&pilha_unidade1) || !pilha_vazia(&pilha_unidade2) || !pilha_vazia(&pilha_unidade3))) {
        tp_jogador jogador;

        if(filaVazia(&fila)) {
            break;
        }

        removeFila(&fila, &jogador);

        printf("\n--- Turno de %s ---\n", jogador.nick);

        if(jogador.perdeuTurno){
            printf("%s perdeu este turno.\n", jogador.nick);
            jogador.perdeuTurno = 0;
            insereFila(&fila, jogador);
            continue;
        }

        int dado = (rand() % 6) + 1;
        printf("%s tirou %d no dado.\n", jogador.nick, dado);
        moverJogador(&jogador, dado, tabuleiro);

        if(jogador.casaAtual.posicao >= ultima_posicao(tabuleiro)){
            printf("\n%s chegou ao fim do tabuleiro!\n", jogador.nick);
            fim_de_jogo = 1;
        } else if(jogador.casaAtual.tipo == 2){
            preparandoPergunta(&jogador, &pilha_unidade1, &pilha_unidade2, &pilha_unidade3);
        } else if(jogador.casaAtual.tipo == 1){
            aplicar_punicao(&jogador, sortear_punicao(), tabuleiro);
        } else {
            printf("Casa normal. Nada acontece.\n");
        }

        insereFila(&fila, jogador);
    }

    printf("\n--- FIM DE JOGO: RESULTADOS ---\n");
    while(!filaVazia(&fila)) {
        tp_jogador j;
        removeFila(&fila, &j);
        printf("\nJogador: %s\n", j.nick);
        printf("Acertos: [F: %d | M: %d | D: %d]\n", j.acertos.facil, j.acertos.medio, j.acertos.dificil);
        printf("Erros: %d\n", j.erros);
    }

    destroiListade(tabuleiro);

    return 0;
}
