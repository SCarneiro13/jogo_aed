#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tabuleiro.h"
#include "baralho.h"// Garante o acesso ao vetor global 'baralho'
#include "punicao.h"

// Função auxiliar para embaralhar um vetor de inteiros (Fisher-Yates)
void embaralhar(int *vetor, int tamanho) {
    for (int i = tamanho - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
}

// Função que cria o caminho com perguntas filtradas por unidade e punições
tp_listade *criar_caminho() {
    tp_listade *lista = inicializaListade();
    int chances;

    // Vetores auxiliares para mapear os índices do baralho correspondentes a cada unidade
    int indices_u1[MAX_PERGUNTAS], qtd_u1 = 0;
    int indices_u2[MAX_PERGUNTAS], qtd_u2 = 0;
    int indices_u3[MAX_PERGUNTAS], qtd_u3 = 0;

    // Classifica os índices do baralho de acordo com as unidades (1, 2 ou 3)
    for (int i = 0; i < MAX_PERGUNTAS; i++) {
        if (baralho[i].unidade == 1) {
            indices_u1[qtd_u1++] = i;
        } else if (baralho[i].unidade == 2) {
            indices_u2[qtd_u2++] = i;
        } else if (baralho[i].unidade == 3) {
            indices_u3[qtd_u3++] = i;
        }
    }

    // Embaralha os índices para garantir o sorteio randômico e sem repetição
    if (qtd_u1 > 0) embaralhar(indices_u1, qtd_u1);
    if (qtd_u2 > 0) embaralhar(indices_u2, qtd_u2);
    if (qtd_u3 > 0) embaralhar(indices_u3, qtd_u3);

    // Contadores para controlar qual pergunta sorteada será inserida na casa
    int p_u1 = 0, p_u2 = 0, p_u3 = 0;

    for (int i = 1; i <= 45; i++) {
        tp_item nova_casa;
        nova_casa.posicao = i;
        nova_casa.punicao = 0; // 0 significa sem punição por padrão

        // Define a unidade da casa baseada na faixa de posições
        if (i <= 15) nova_casa.unidade = 1;
        else if (i <= 30) nova_casa.unidade = 2;
        else nova_casa.unidade = 3;

        chances = rand() % 100;

        if (i == 45) {
            nova_casa.tipo = 0; // Última casa é sempre normal
        } else if (chances < 35) {
            nova_casa.tipo = 2; // Tipo Pergunta
            
            // Atribui a pergunta baseada na unidade atual da casa
            if (nova_casa.unidade == 1 && qtd_u1 > 0) {
                // p_u1 % qtd_u1 garante que se faltar pergunta, ele recicle sem estourar o vetor
                nova_casa.pergunta = baralho[indices_u1[p_u1 % qtd_u1]];
                p_u1++;
            } 
            else if (nova_casa.unidade == 2 && qtd_u2 > 0) {
                nova_casa.pergunta = baralho[indices_u2[p_u2 % qtd_u2]];
                p_u2++;
            } 
            else if (nova_casa.unidade == 3 && qtd_u3 > 0) {
                nova_casa.pergunta = baralho[indices_u3[p_u3 % qtd_u3]];
                p_u3++;
            }
        } else if (chances < 50) {
            nova_casa.tipo = 1; // Tipo Especial (Com Punição)
            
            // Sorteia o ID de uma punição de 1 a 3
            // 1: Volte 2 casas | 2: Perda de 1 turno | 3: Volte para o início da unidade
            nova_casa.punicao = (rand() % 3) + 1; 
        } else {
            nova_casa.tipo = 0; // Tipo Normal
        }

        insereListadeOrdem(lista, nova_casa);
    }

    return lista;
}
