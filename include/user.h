#ifndef USER_H
#define USER_H

#include "space.h"
#include "ARVB.H"

typedef struct {
    int dificil;
    int medio;
    int facil;
} tp_acertos;

typedef struct {
    TipoApontador raiz;
    int total_casas;
} tp_registro_casas;

typedef struct {
    char nick[30];
    tp_space casaAtual;
    tp_acertos acertos;
    int erros;
    int perdeuTurno;
    tp_registro_casas visitas;
} tp_jogador;

void inicializa_registro(tp_registro_casas *registro, int total_casas);
void registrar_casa(tp_registro_casas *registro, int casa);
void liberar_registro(tp_registro_casas *registro);
void imprimir_resumo_casas(const tp_registro_casas *registro);
void cadastrarJogador(tp_jogador *j);
void inicializarJogador(tp_jogador *j);

#endif
