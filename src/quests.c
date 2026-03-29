#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "quests.h"
#include "stack.h"

void embaralharPerguntas(tp_pergunta *baralho, tp_baralho *uni1, tp_baralho *uni2, tp_baralho *uni3){
    for (int i = MAX - 1; i > 0; i--) { // Embaralhando o baralho
        int j = rand() % (i + 1);

        tp_pergunta temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }

    for(int i = 0; i < MAX; i++){ // Separando nas pilhas das unidades
        switch(baralho[i].unidade){
            case 1:
                push(uni1, baralho[i]);
                break;
            case 2:
                push(uni2, baralho[i]);
                break;
            case 3:
                push(uni3, baralho[i]);
                break;
            default:
                printf("Error: unidade invalida.");
                break;
        }
    }

    return;
}