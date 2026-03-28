#include <stdio.h>
#include "usuario.h"
#include "fila.h"

// Cadastra os nomes dos jogadores
void cadastrarJogador(Jogador *j){
    printf("Nome do jogador: ");
    scanf(" %[^\n]s", j->nick);
}

// Inicializa os dados do jogador
void inicializarJogador(Jogador *j){
    j->casaAtual = 0;
    j->acertos.facil = 0;
    j->acertos.medio = 0;
    j->acertos.dificil = 0;
    j->erros = 0;
}