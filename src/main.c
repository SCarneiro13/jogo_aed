#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "quests.h"
#include "stack.h"
#include "queue.h"
#include "user.h"

int main(){

/*INICIALIZAÇÃO BASE DO JOGO*/

    srand(time(NULL)); // Comando para randomizar e embaralhar o baralho.

/*PREPARANDO BARALHOS DE CADA UNIDADE*/

    tp_pergunta baralho[MAX_PERGUNTAS] = { // Baralho com as perguntas.
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

tp_baralho pilha_unidade1, pilha_unidade2, pilha_unidade3; // Baralho de cada unidade
inicializa_pilha(&pilha_unidade1);
inicializa_pilha(&pilha_unidade2);
inicializa_pilha(&pilha_unidade3);

embaralharPerguntas(baralho, &pilha_unidade1, &pilha_unidade2, &pilha_unidade3); // Função para embaralhar, está definida em quests.h e codada em quests.c

/*PREPARANDO PARA RECEBER USUARIOS*/

 int qtdJog;
tp_fila fila;
inicializaFila(&fila);

/*INICIAÇÃO PROVISÓRIA DO JOGO*/

printf("BEM VINDO AO JOGO!\n\n");

do {
        printf("Quantos jogadores (2 a 4): ");
        scanf("%d", &qtdJog);
    } while(qtdJog < 2 || qtdJog > 4);

    for(int i = 0; i < qtdJog; i++){
        Jogador j;
        
        printf("\n---JOGADOR %d---\n", i+1);

        cadastrarJogador(&j);
        inicializarJogador(&j);

        insereFila(&fila, j);

    }
    
    Jogador temp;
    int i = 0;
    while(!filaVazia(&fila)){
        removeFila(&fila, &temp);
        printf("Jogador %d: %s\n", i+1, temp.nick);
    }

    return 0;
}