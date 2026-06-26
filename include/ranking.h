#ifndef RANKING_H
#define RANKING_H

#include "user.h"
#include "quests.h"

#define ARQUIVO_RANKING "ranking.dat"
#define MAX_PERG_JOGADOR 50 // Garante espaço suficiente para as rodadas

// Calcula a pontuação total de um jogador com base no peso das dificuldade
int calcular_pontuacao(tp_jogador *j);

// Salva (acrescenta) o registro do jogador atual no arquivo binário em disco
void salvar_pontuacao(tp_jogador *j);

// Lê o arquivo binário, ordena de forma decrescente e exibe os enunciados cruzando os IDs
void exibir_ranking(tp_pergunta *banco_completo, int nmr_questoes);

#endif