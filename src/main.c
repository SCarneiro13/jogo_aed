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
#include "vencedor.h"

void mostrarMenuInicial(){
    printf("====================================\n");
    printf("            MENU PRINCIPAL          \n");
    printf("====================================\n");
    printf("1 - Comecar o jogo\n");
    printf("2 - Regras rapidas\n");
    printf("3 - Sair\n");
    printf("Escolha uma opcao: ");
}

void mostrarPosicoes(tp_jogador *jogadorAtual, tp_fila *fila){
    printf("\n\n\n\n\n--- Posicoes dos jogadores ---\n");
    printf("%s -> casa %d\n", jogadorAtual->nick, jogadorAtual->casaAtual.posicao);

    int i = proximo(fila->ini);
    int limite = proximo(fila->fim);
    while(i != limite){
        printf("%s -> casa %d\n", fila->item[i].nick, fila->item[i].casaAtual.posicao);
        i = proximo(i);
    }
}

void mostrarProximasCasas(tp_jogador *jogador, tp_listade *tabuleiro){
    int inicio = jogador->casaAtual.posicao;
    int fim = ultima_posicao(tabuleiro);

    printf("\n--- Proximas 10 casas a partir de %s ---\n", jogador->nick);
    for(int k = 0; k < 10 && inicio + k <= fim; k++){
        tp_space casa;
        if(buscar_casa(tabuleiro, inicio + k, &casa)){
            const char *tipo = (casa.tipo == 2) ? "Pergunta" : (casa.tipo == 1 ? "Punicao" : "Normal");
            printf("Casa %d (%s)\n", casa.posicao, tipo);
        }
    }
    printf("\n\n\n\n\n");
}

void mostrarPontos(tp_jogador *jogadorAtual, tp_fila *fila){
    printf("\n\n\n\n\n--- Pontos dos jogadores ---\n");

    printf("\n%s -> F: %d | M: %d | D: %d\n",
           jogadorAtual->nick,
           jogadorAtual->acertos.facil,
           jogadorAtual->acertos.medio,
           jogadorAtual->acertos.dificil);

    int i = proximo(fila->ini);
    int limite = proximo(fila->fim);
    while(i != limite){
        tp_jogador j = fila->item[i];
        printf("\n%s -> F: %d | M: %d | D: %d\n",
               j.nick,
               j.acertos.facil,
               j.acertos.medio,
               j.acertos.dificil);
        i = proximo(i);
    }

    printf("\n\n\n\n\n");
}

int menuDeAcao(tp_jogador *jogador, tp_fila *fila, tp_listade *tabuleiro){
    int escolha;

    do{
        printf("\n=== Acoes de %s ===\n", jogador->nick);
        printf("1 - Jogar dado\n");
        printf("2 - Usar item (a ser implementado)\n");
        printf("3 - Ver as proximas 10 casas\n");
        printf("4 - Mostrar pontos\n");
        printf("Escolha uma opcao: ");
        scanf(" %d", &escolha);

        switch(escolha){
            case 1:
                return 1;
            case 2:
                printf("\nOpcao de item ainda nao implementada.\n\n\n\n\n");
                break;
            case 3:
                mostrarPosicoes(jogador, fila);
                mostrarProximasCasas(jogador, tabuleiro);
                break;
            case 4:
                mostrarPontos(jogador, fila);
                break;
            default:
                printf("\nOpcao invalida.\n");
                break;
        }
    } while(1);
}

int main() {
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

    int opcaoInicial;
    do{
        mostrarMenuInicial();
        scanf(" %d", &opcaoInicial);

        if(opcaoInicial == 1){
            break;
        } else if(opcaoInicial == 2){
            printf("\nRegras rapidas:\n");
            printf("- Cada jogador deve responder perguntas nas casas especiais.\n");
            printf("- Antes de jogar o dado, voce pode consultar posicoes, casas futuras ou usar um item.\n\n\n\n\n");
        } else if(opcaoInicial == 3){
            printf("\nEncerrando o jogo...\n");
            return 0;
        } else {
            printf("\nOpcao invalida.\n");
        }
    } while(1);

    printf("\n\n\n\n\nBEM VINDO AO JOGO!\n");
    criarJogadores(&fila);

    while(!fim_de_jogo) {
        tp_jogador jogador;

        if(filaVazia(&fila)) {
            break;
        }

        removeFila(&fila, &jogador);

        printf("\n\n\n\n\n--- Turno de %s ---\n", jogador.nick);

        if(jogador.perdeuTurno){
            printf("%s perdeu este turno.\n", jogador.nick);
            jogador.perdeuTurno = 0;
            insereFila(&fila, jogador);
            continue;
        }

        menuDeAcao(&jogador, &fila, tabuleiro);
        int dado = (rand() % 6) + 1;
        printf("\n\n\n\n\n%s tirou %d no dado.\n", jogador.nick, dado);
        moverJogador(&jogador, dado, tabuleiro);
        registrar_casa(&resumo_geral, jogador.casaAtual.posicao);

        if(verificar_vencedor(&jogador, tabuleiro)) {
            printf("\n%s chegou ao fim do tabuleiro e VENCEU O JOGO!\n", jogador.nick);
            strcpy(nome_vencedor, jogador.nick); 
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

    printf("\nResumo geral de casas visitadas:\n");
    imprimir_resumo_casas(&resumo_geral);
    liberar_registro(&resumo_geral);

    destroiListade(tabuleiro);

    return 0;
}
