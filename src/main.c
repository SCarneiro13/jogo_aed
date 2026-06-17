#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "quests.h"
#include "stack.h"
#include "queue.h"
#include "user.h"
#include "baralho.h"
#include "criarJogadores.h"
#include "tabuleiro.h"
#include "movimentacao.h"
#include "punicao.h"
#include "vencedor.h" // <-- Novo include adicionado

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    srand(time(NULL));

    tp_fila fila;
    inicializaFila(&fila);

    tp_listade *tabuleiro = criar_caminho();
    int fim_de_jogo = 0;
    char nome_vencedor[50] = ""; // Para guardar quem ganhou para o fim do jogo

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

    while(!fim_de_jogo) {
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

        // <-- AQUI ENTRA A FUNÇÃO DE VENCEDOR -->
        if(verificar_vencedor(&jogador, tabuleiro)) {
            printf("\n%s chegou ao fim do tabuleiro e VENCEU O JOGO!\n", jogador.nick);
            strcpy(nome_vencedor, jogador.nick); // Salva o nome do campeão
            fim_de_jogo = 1;
        } else if(jogador.casaAtual.tipo == 2){
            preparandoPergunta(&jogador, &pilha_unidade1, &pilha_unidade2, &pilha_unidade3, baralho, MAX_PERGUNTAS);
        } else if(jogador.casaAtual.tipo == 1){
            aplicar_punicao(&jogador, sortear_punicao(), tabuleiro);
        } else {
            printf("Casa normal. Nada acontece.\n");
        }

        insereFila(&fila, jogador);
    }

    printf("\n===============================\n");
    printf("   FIM DE JOGO: RESULTADOS\n");
    printf("===============================\n");
    
    if(strlen(nome_vencedor) > 0) {
        printf("\n*** O GRANDE CAMPEAO: %s ***\n", nome_vencedor);
    }

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
