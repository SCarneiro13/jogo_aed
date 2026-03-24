#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quests.h"
#include "stack.h"
#include "queue.h"

void embaralha_perguntas(tp_baralho *geral){
    tp_baralho2 baux;
    inicializa_pilha(&baux);
    tp_pergunta paux;
    int min = 1, max = MAX, num;
    srand(time(NULL)); // Inicializa o gerador com o tempo atual para aleatoriedade.

    for(int i = 0; i < 5; i++){
        num = (rand() % (max - min + 1)) + min; // Sorteia um número entre min e max
        for(int j = 0; j < num; j++){ // Joga uma quantidade aleatoria de cartas do fim para a paux
            pop(geral, &paux);      
            push(&baux, paux);
        }


    }
}

tp_baralho baralho[MAX] = {
    {
        1, // Unidade.
        0, // Dificuldade.
        "Qual o maior time do mundo?", // Pergunta.
        {"Palmeiras", "Flamengo", "BAHEA", "Santos", "São Paulo"}, // Alternativas.
        2 // Indice da resposta certa em alternativas.
    },
    {
        1,
        0,
        "Qual o menor time da historia?",
        {"Vicetoria", "Remo", "Jacuipense", "Vasco", "Outro"},
        0
    }
};