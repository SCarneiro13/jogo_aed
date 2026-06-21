#ifndef USER_H
#define USER_H
#include "space.h"

#define MAX_PERG_JOGADOR 27

typedef struct{
    int dificil;
    int medio;
    int facil;
} tp_acertos;

typedef struct{
    char nick[30]; // Nome do usuario
    tp_space casaAtual;
    tp_acertos acertos;
    int erros;
    int perdeuTurno;

    // Histórico de perguntas (ids referentes ao array banco_completo/baralho)
    int id_certas[MAX_PERG_JOGADOR];
    int qtd_certas;
    int id_erradas[MAX_PERG_JOGADOR];
    int qtd_erradas;
} tp_jogador;

void cadastrarJogador(tp_jogador *j);
void inicializarJogador(tp_jogador *j);
#endif
