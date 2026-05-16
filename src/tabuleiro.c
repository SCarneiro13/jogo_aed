#include <stdio.h>
#include "tabuleiro.h"
#include <time.h>
#include "punicao.h"

// função que cria o caminho -> adiciona as casas na lista, cada casa com sua unidade, posição e tipo (normal, especial ou pergunta)
tp_listade *criar_caminho(){
    tp_listade *lista = inicializaListade();
    int chances;

    for(int i = 1; i <= 45; i++){
        tp_item nova_casa;
        nova_casa.posicao = i;

        if (i <= 15) nova_casa.unidade = 1;
            
        else if (i<= 30) nova_casa.unidade = 2;
        else nova_casa.unidade = 3;

        chances = rand() % 100; // pega um numero entre 0 e 99 para não deixar o tabuleiro previsível

        if(i == 45) nova_casa.tipo = 0; // garantir que a última casa é normal
        else if(chances < 35) nova_casa.tipo = 2; // entre 0 e 34 -> 35% de chance de ser do tipo pergunta
        else if(chances < 50) nova_casa.tipo = 1; // entre 35 a 49 -> 15% de chhance de ser do tipo especial
        else nova_casa.tipo = 0; // 50 a 99 -> 50% de chance de ser do tipo normal

        insereListadeOrdem(lista, nova_casa); // insere a nova_casa na lista já com a posição, unidade e tipo
    }

    return lista;
}
