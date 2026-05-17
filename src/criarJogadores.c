#include <stdio.h>
#include "criarJogadores.h"
#include "queue.h"
#include "user.h"

void criarJogadores(tp_fila *fila){
    int qtdJog = 0;
    int leitura;

    while(qtdJog < 2 || qtdJog > 4){
        printf("Quantos jogadores (2 a 4): ");
        fflush(stdout);

        leitura = scanf("%d", &qtdJog);
        if(leitura != 1){
            int ch;

            printf("Entrada invalida. Digite um numero entre 2 e 4.\n");
            while((ch = getchar()) != '\n' && ch != EOF);
            qtdJog = 0;
        }
    }

    for(int i = 0; i < qtdJog; i++){
        tp_jogador j;
        
        printf("\n---JOGADOR %d---\n", i+1);

        cadastrarJogador(&j);
        inicializarJogador(&j);

        insereFila(fila, j);
    }
}
