#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "quests.h"
#include "stack.h"

void embaralharPerguntas(tp_pergunta *baralho, int num_questions, tp_baralho *uni1, tp_baralho *uni2, tp_baralho *uni3){
    for (int i = num_questions - 1; i > 0; i--) { // Embaralhando o baralho
        int j = rand() % (i + 1);

        tp_pergunta temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }



    for(int i = 0; i < num_questions; i++){ // Separando nas pilhas das unidades
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
                printf("Error: unidade invalida.\n");
                break;
        }
    }

    return;
}



void preparandoPergunta(tp_jogador *j, tp_baralho *uni1, tp_baralho *uni2, tp_baralho *uni3){
    int resposta; // Variavel vai ser usada para saber se jogador acertou ou errou.
    

    printf("\n--- Pergunta para %s ---\n", j->nick);
    switch (j->casaAtual.unidade) // Pegando a unidade da casa atual do jogador.
    {
    case 1: // Caso seja a unidade 1.
        resposta = fazerPergunta(uni1);
        break;
    case 2: // Caso seja a unidade 2.
        resposta = fazerPergunta(uni2);
        break;
    case 3: // Caso seja a unidade 3.
        resposta = fazerPergunta(uni3);
        break;
    default: // Caso a unidade não seja valida.
        printf("Error. \nCasa indeterminda");
        break;
    }

    switch (resposta) // Somando na quantidade do acerto/erro
    {
    case 0:
        j->erros++;
        break;
    case 1:
        j->acertos.facil++;
        break;
    case 2:
        j->acertos.medio++;
        break;
    case 3:
        j->acertos.dificil++;
        break;
    }
}



int fazerPergunta(tp_baralho *uni){
    tp_pergunta questao;
    pop(uni, &questao); // Pegando uma questão do topo do baralho.
    int resposta; // Variavel vai ser usada para saber se jogador acertou ou errou.

    printf("Pergunta: %s\n\n", questao.pergunta); // Fazendo a pergunta.

    for(int i = 0; i < 5; i++){ // Mostrando as alternativas.
        printf("%d) %s\n", i+1, questao.alternativas[i]);
    }

    printf("\nSua resposta (1-5): ");
        scanf("%d", &resposta); // Coletando a resposta do jogador

    if(resposta-1 == questao.resposta){ // Se a resposta for correta
        printf("\nPARABENS! Resposta correta.\n");
        switch (questao.dificuldade) // Verificando a dificuldade da questão.
        {
        case 0: 
            return 1;
            break;
        case 1:
            return 2;
            break;
        case 2:
            return 3;
            break;
        default:
            printf("Error. \nQuestão com dificuldade indeterminada");
            break;
        };
    }else{ // Se a resposta for errada
        printf("\nPoxa... resposta incorreta.\n");
        return 0;
    }
}