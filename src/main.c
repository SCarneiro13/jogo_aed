#include <stdio.h>
#include "criarJogadores.h"
#include "queue.h"
#include "user.h"
#include "movimentacao.h"

int main(){
    tp_fila fila;
    inicializaFila(&fila);

    criarJogadores(&fila);

    return 0;
}

int dado;
tp_jogador jogadorAtual;

while(1){

    removerFila(&fila, &jogadorAtual);

    printf("\nVez de %s\n", jogadorAtual.nome);

    dado = rand() % 6 + 1;

    printf("Dado: %d\n", dado);

    moverJogador(&jogadorAtual, dado);

    if(jogadorAtual.posicao >= 30){
        printf("\n%s venceu o jogo!\n", jogadorAtual.nome);
        break;
    }

    inserirFila(&fila, jogadorAtual);
}
