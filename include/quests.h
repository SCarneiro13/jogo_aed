#ifndef QUESTS_H
#define QUESTS_H

#define MAX_PERGUNTAS 27

#include "space.h"
#include "user.h"

// A pergunta deve ser relacionada com sua unidade e ter um nível de dificuldade.

typedef struct{
    char id[10]; // Identificador da pergunta
    int unidade; // Unidade da pergunta.
    int dificuldade; // Nivel de dificuldade (De 0 a 2).
    char tema[50]; // Tema da pergunta
    char subtema[50]; // Subtema da pergunta
    char pergunta[500]; // A pergunta.
    char alternativas[5][250]; // Alternativas -> 5 alternativas de ate 250 caracteres.
    int resposta; // Resposta correta (Indice de alternativas, vai de 0 a 4).
} tp_pergunta;

// Um baralho que é basicamente uma fila de perguntas.

typedef struct{
    tp_pergunta pergunta[MAX_PERGUNTAS/3];
    int topo;
} tp_baralho;



void embaralharPerguntas(tp_pergunta *baralho, int num_questions, tp_baralho *uni1, tp_baralho *uni2, tp_baralho *uni3); // Função para embaralhar.

void preparandoPergunta(tp_jogador *jogador, tp_baralho *uni1, tp_baralho *uni2, tp_baralho *uni3, tp_pergunta *banco_completo, int nmr_questoes); // Função para preparar a pergunta.

int fazerPergunta(tp_baralho *uni, tp_pergunta *banco_completo, int nmr_questoes, int unidade); // Função para realizar a pergunta.

void reporPerguntas(int unidade, tp_pergunta *banco_completo, int nmr_questoes, tp_baralho *uni_atual); // Função para repor as perguntas 

void salvarHistoricoResposta (char nomeJogador[], tp_pergunta p, int respJogador, char resultado[]); // Função para salvar o historico das respostas

void gerarArquivoReferencia (tp_pergunta *banco_completo, int nmr_questoes) // Função para gerar o arquivo de referência das perguntas
#endif
