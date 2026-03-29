#ifndef QUESTS_H
#define QUESTS_H

#define MAX 27

// A pergunta deve ser relacionada com sua unidade e ter um nível de dificuldade.

typedef struct{
    int unidade; // Unidade da pergunta.
    int dificuldade; // Nivel de dificuldade (De 0 a 2).
    char pergunta[100]; // A pergunta.
    char alternativas[5][50]; // Alternativas -> 5 alternativas de 50 caracteres.
    int resposta; // Resposta correta (Indice de alternativas, vai de 0 a 4).
} tp_pergunta;

// Um baralho que é basicamente uma fila de perguntas.

typedef struct{
    tp_pergunta pergunta[MAX/3];
    int topo;
} tp_baralho;



void embaralharPerguntas(tp_pergunta *baralho, tp_baralho *uni1, tp_baralho *uni2, tp_baralho *uni3); // Função para embaralhar.


#endif