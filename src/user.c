#include <stdio.h>
#include "user.h"
#include "queue.h"

// Cadastra os nomes dos jogadores
void cadastrarJogador(tp_jogador *j){
    printf("Nome do jogador: ");
    scanf(" %[^\n]", j->nick);
}

// Inicializa os dados do jogador
void inicializarJogador(tp_jogador *j){
    j->casaAtual.posicao = 0;
    j->casaAtual.tipo = 1;
    j->casaAtual.unidade = 1;
    j->acertos.facil = 0;
    j->acertos.medio = 0;
    j->acertos.dificil = 0;
    j->erros = 0;
}