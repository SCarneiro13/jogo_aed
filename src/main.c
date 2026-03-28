#include <stdio.h>
#include "fila.h"
#include "usuario.h"

int main(){
    int qtdJog;
    tp_fila fila;
    inicializaFila(&fila);

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
    
    tp_jogador temp;
    int i = 0;
    while(!filaVazia(&fila)){
        removeFila(&fila, &temp);
        printf("Jogador %d: %s\n", i+1, temp.nick);
    }
    return 0;
}