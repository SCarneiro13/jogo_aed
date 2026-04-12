#include <stdio.h>
#include "criarJogadores.h"
#include "queue.h"   // ou onde estiver tp_fila
#include "user.h"    // ou onde estiver tp_jogador

void criarJogadores(tp_fila *fila){
    int qtdJog;

    do {
        printf("Quantos jogadores (2 a 4): ");
        scanf("%d", &qtdJog);
    } while(qtdJog < 2 || qtdJog > 4);

    for(int i = 0; i < qtdJog; i++){
        tp_jogador j;
        
        printf("\n---JOGADOR %d---\n", i+1);

        cadastrarJogador(&j);
        inicializarJogador(&j);

        insereFila(fila, j);
    }
}
