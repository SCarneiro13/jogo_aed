#ifndef QUESTS_H
#define QUESTS_H

#define MAX_PERGUNTAS 27

#include "space.h"
#include "user.h"

// A pergunta deve ser relacionada com sua unidade e ter um nível de dificuldade.

typedef struct{
    int unidade; // Unidade da pergunta.
    int dificuldade; // Nivel de dificuldade (De 0 a 2).
    char pergunta[500]; // A pergunta.
    char alternativas[5][100]; // Alternativas -> 5 alternativas de 100 caracteres.
    int resposta; // Resposta correta (Indice de alternativas, vai de 0 a 4).
} tp_pergunta;

// Um baralho que é basicamente uma fila de perguntas.

typedef struct{
    tp_pergunta pergunta[MAX_PERGUNTAS/3];
    int topo;
} tp_baralho;



void embaralharPerguntas(tp_pergunta *baralho, int num_questions, tp_baralho *uni1, tp_baralho *uni2, tp_baralho *uni3); // Função para embaralhar.

void preparandoPergunta(tp_jogador *jogador, tp_baralho *uni1, tp_baralho *uni2, tp_baralho *uni3); // Função para preparar a pergunta.

int fazerPergunta(tp_baralho *uni); // Função para realizar a pergunta.

#endif