#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "quests.h"
#include "stack.h"
#include "queue.h"
#include "user.h"
#include "baralho.h"
#include "criarJogadores.h"

int main(){

/*INICIALIZAÇÃO BASE DO JOGO*/

    srand(time(NULL)); // Comando para randomizar e embaralhar o baralho.

/*PREPARANDO BARALHOS DE CADA UNIDADE*/

tp_baralho pilha_unidade1, pilha_unidade2, pilha_unidade3; // Baralho de cada unidade
inicializa_pilha(&pilha_unidade1);
inicializa_pilha(&pilha_unidade2);
inicializa_pilha(&pilha_unidade3);

/*CONTANDO QUANTIDADE DE PERGUNTAS*/
int num_questions = 0;
for(int i = 0; i < MAX_PERGUNTAS; i++){
    if(baralho[i].unidade != 0){
        num_questions++;
    }
}

embaralharPerguntas(baralho, num_questions, &pilha_unidade1, &pilha_unidade2, &pilha_unidade3); // Função para embaralhar, está definida em quests.h e codada em quests.c

/*PREPARANDO PARA RECEBER USUARIOS*/

int qtdJog;
tp_fila fila;
inicializaFila(&fila);

/*INICIAÇÃO PROVISÓRIA DO JOGO*/

printf("BEM VINDO AO JOGO!\n\n");

tp_fila fila;
inicializaFila(&fila);
criarJogadores(&fila);


    while(!pilha_vazia(&pilha_unidade1)){
        tp_jogador jogador;
        removeFila(&fila, &jogador);
        preparandoPergunta(&jogador, &pilha_unidade1, &pilha_unidade2, &pilha_unidade3);
        insereFila(&fila, jogador);
    }

    while(!filaVazia(&fila)){
        tp_jogador j;
        removeFila(&fila, &j);
        printf("\n--- Resultado de %s ---\n", j.nick);
        printf("Acertos fáceis: %d\n", j.acertos.facil);
        printf("Acertos médios: %d\n", j.acertos.medio);
        printf("Acertos difíceis: %d\n", j.acertos.dificil);
        printf("Erros: %d\n", j.erros);
    }


    return 0;
}
