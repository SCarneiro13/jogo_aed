#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "quests.h"
#include "stack.h"
#include "queue.h"
#include "user.h"
#include "baralho.h"
#include "criarJogadores.h"

int main() {
    srand(time(NULL));

    // 1. INICIALIZAÇÃO DA FILA E VARIÁVEIS
    tp_fila fila;
    inicializaFila(&fila); 

    // 2. PREPARANDO BARALHOS
    tp_baralho pilha_unidade1, pilha_unidade2, pilha_unidade3;
    inicializa_pilha(&pilha_unidade1);
    inicializa_pilha(&pilha_unidade2);
    inicializa_pilha(&pilha_unidade3);

    // 3. CONTANDO E EMBARALHANDO PERGUNTAS
    int num_questions = 0;
    for(int i = 0; i < MAX_PERGUNTAS; i++) {
        if(baralho[i].unidade != 0) {
            num_questions++;
        }
    }
    embaralharPerguntas(baralho, num_questions, &pilha_unidade1, &pilha_unidade2, &pilha_unidade3);

    // 4. CADASTRO DE JOGADORES 
    printf("BEM VINDO AO JOGO!\n\n");
    criarJogadores(&fila); 

    // 5. LOOP DO JOGO (Enquanto houver perguntas na unidade 1)
    while(!pilha_vazia(&pilha_unidade1)) {
        tp_jogador jogador;
        if(!filaVazia(&fila)) {
            removeFila(&fila, &jogador);
            preparandoPergunta(&jogador, &pilha_unidade1, &pilha_unidade2, &pilha_unidade3);
            insereFila(&fila, jogador);
        } else {
            break; // Sai do loop se não houver jogadores
        }
    }

    // 6. RESULTADOS FINAIS
    printf("\n--- FIM DE JOGO: RESULTADOS ---\n");
    while(!filaVazia(&fila)) {
        tp_jogador j;
        removeFila(&fila, &j);
        printf("\nJogador: %s\n", j.nick);
        printf("Acertos: [F: %d | M: %d | D: %d]\n", j.acertos.facil, j.acertos.medio, j.acertos.dificil);
        printf("Erros: %d\n", j.erros);
    }

    return 0;
}