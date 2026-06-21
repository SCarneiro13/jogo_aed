#ifndef RANKING_H
#define RANKING_H

#include "user.h"
#include "quests.h"

#define ARQUIVO_RANKING "ranking.dat"

// Calcula a pontuação total de um jogador (ajuste os pesos se quiser).
int calcular_pontuacao(tp_jogador *j);

// Salva (acrescenta) o resultado de um jogador no arquivo em disco.
// Deve ser chamada uma vez para cada jogador, ao final da partida.
void salvar_pontuacao(tp_jogador *j);

// Lê todos os registros do arquivo, ordena por pontuação (maior -> menor)
// e imprime o ranking, mostrando as perguntas certas/erradas de cada um.
// 'banco_completo' é o array global de perguntas (baralho[]), usado para
// recuperar o texto das perguntas a partir dos índices salvos.
void exibir_ranking(tp_pergunta *banco_completo, int nmr_questoes);

#endif
