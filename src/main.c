#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

#include "quests.h"
#include "stack.h"
#include "queue.h"
#include "user.h"
#include "baralho.h"
#include "criarJogadores.h"
#include "tabuleiro.h"
#include "movimentacao.h"
#include "punicao.h"
#include "vencedor.h"
#include "interface.h"
#include "acao.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    setvbuf(stdout, NULL, _IONBF, 0);
    srand(time(NULL));

    tp_fila fila;
    inicializaFila(&fila);

    tp_listade *tabuleiro = criar_caminho();
    tp_registro_casas resumo_geral;
    inicializa_registro(&resumo_geral, ultima_posicao(tabuleiro));

    int fim_de_jogo = 0;
    char nome_vencedor[50] = "";

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


    FILE *arq_init = fopen("historico_respostas.csv", "w");
    if(arq_init != NULL){
        fprintf(arq_init, "turma;nome_jogador;id_pergunta;unidade;tema;subtema;dificuldade;resposta_jogador;resposta_correta;resultado\n");
        fclose(arq_init);
    }
    
    gerarArquivoReferencia(baralho, num_questions);


    int opcaoInicial;
    do{
        mostrar_menu();
        scanf(" %d", &opcaoInicial);

        if(opcaoInicial == 1){
            break;
        } else if(opcaoInicial == 2){
            encerramento_jogo();
            return 0;
        } else {
            continue;
        }
    } while(1);

    criarJogadores(&fila);

    while(!fim_de_jogo) {
        tp_jogador jogador;

        if(filaVazia(&fila)) {
            break;
        }

        removeFila(&fila, &jogador);

        if(jogador.perdeuTurno){
            perdeu_turno(&jogador);
            jogador.perdeuTurno = 0;
            insereFila(&fila, jogador);
            continue;
        }

        menuDeAcao(&jogador, &fila, tabuleiro);
        int dado = (rand() % 6) + 1;
        mostrar_dado(dado);
        moverJogador(&jogador, dado, tabuleiro);
        registrar_casa(&resumo_geral, jogador.casaAtual.posicao);

        if(verificar_vencedor(&jogador, tabuleiro)) {
            venceu_jogo(&jogador);
            strcpy(nome_vencedor, jogador.nick); 
            fim_de_jogo = 1;
        } else if(jogador.casaAtual.tipo == 2){
            preparandoPergunta(&jogador, &pilha_unidade1, &pilha_unidade2, &pilha_unidade3, baralho, MAX_PERGUNTAS);
        } else if(jogador.casaAtual.tipo == 1){
            aplicar_punicao(&jogador, sortear_punicao(), tabuleiro);
        } else {
            casa_normal();
        }

        insereFila(&fila, jogador);
    }

    final_de_jogo();
    
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

    printf("\nResumo geral de casas visitadas:\n");
    imprimir_resumo_casas(&resumo_geral);
    liberar_registro(&resumo_geral);

    destroiListade(tabuleiro);

    return 0;
}
