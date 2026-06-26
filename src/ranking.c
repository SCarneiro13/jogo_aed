#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ranking.h"

// Definindo um tamanho máximo seguro de perguntas que um único jogador pode responder na partida
#define MAX_PERG_JOGADOR 50

/* ---------------------------------------------------------
   Estrutura que efetivamente vai pro disco.
   Igual a tp_jogador, mas isolada aqui pra não depender de
   mudanças futuras na struct usada durante a partida.
--------------------------------------------------------- */
typedef struct {
    char nick[30];
    tp_acertos acertos;
    int erros;
    int pontuacao;
    char id_certas[MAX_PERG_JOGADOR][10];  // Ajustado para strings de ID
    int qtd_certas;
    char id_erradas[MAX_PERG_JOGADOR][10]; // Ajustado para strings de ID
    int qtd_erradas;
} tp_registro;

int calcular_pontuacao(tp_jogador *j) {
    // Multiplica acertos pelo peso da dificuldade e subtrai penalidade por erros
    return (j->acertos.facil * 10) + (j->acertos.medio * 20) + (j->acertos.dificil * 30) - (j->erros * 5);
}

void salvar_pontuacao(tp_jogador *j) {
    tp_registro reg;
    memset(&reg, 0, sizeof(tp_registro));

    strncpy(reg.nick, j->nick, sizeof(reg.nick) - 1);
    reg.acertos = j->acertos;
    reg.erros = j->erros;
    reg.pontuacao = calcular_pontuacao(j);

    // Salvando os IDs das perguntas acertadas (copiando as strings de ID)
    reg.qtd_certas = j->qtd_certas;
    for (int i = 0; i < j->qtd_certas && i < MAX_PERG_JOGADOR; i++) {
        strncpy(reg.id_certas[i], j->id_certas[i], 9);
    }

    // Salvando os IDs das perguntas erradas (copiando as strings de ID)
    reg.qtd_erradas = j->qtd_erradas;
    for (int i = 0; i < j->qtd_erradas && i < MAX_PERG_JOGADOR; i++) {
        strncpy(reg.id_erradas[i], j->id_erradas[i], 9);
    }

    FILE *f = fopen(ARQUIVO_RANKING, "ab"); // Append binário
    if (!f) {
        printf("Erro ao abrir %s para escrita.\n", ARQUIVO_RANKING);
        return;
    }
    fwrite(&reg, sizeof(tp_registro), 1, f);
    fclose(f);
}

// Comparador para o qsort: Maior pontuação primeiro no topo
static int comparar_registros(const void *a, const void *b) {
    const tp_registro *ra = (const tp_registro *)a;
    const tp_registro *rb = (const tp_registro *)b;
    return rb->pontuacao - ra->pontuacao;
}

// Função auxiliar interna para buscar o enunciado pelo ID textual dentro do baralho
static const char* buscar_enunciado_por_id(char *id, tp_pergunta *banco_completo, int nmr_questoes) {
    for (int i = 0; i < nmr_questoes; i++) {
        if (strcmp(banco_completo[i].id, id) == 0) {
            return banco_completo[i].pergunta; // Retorna o texto do enunciado
        }
    }
    return "Enunciado nao encontrado (ID invalido)";
}

void exibir_ranking(tp_pergunta *banco_completo, int nmr_questoes) {
    FILE *f = fopen(ARQUIVO_RANKING, "rb");
    if (!f) {
        printf("\nAinda nao ha partidas registradas no ranking.\n");
        return;
    }

    // Descobre a quantidade de registros gravados calculando o tamanho total do arquivo
    fseek(f, 0, SEEK_END);
    long tamanho = ftell(f);
    fseek(f, 0, SEEK_SET);
    int total = tamanho / sizeof(tp_registro);

    if (total == 0) {
        printf("\nAinda nao ha partidas registradas no ranking.\n");
        fclose(f);
        return;
    }

    tp_registro *registros = malloc(total * sizeof(tp_registro));
    if (!registros) {
        printf("Erro de alocacao de memoria ao ler o ranking.\n");
        fclose(f);
        return;
    }

    fread(registros, sizeof(tp_registro), total, f);
    fclose(f);

    // Ordena do maior score para o menor
    qsort(registros, total, sizeof(tp_registro), comparar_registros);

    printf("\n======================================================\n");
    printf("                RANKING GERAL HISTORICO               \n");
    printf("======================================================\n");

    for (int i = 0; i < total; i++) {
        tp_registro *r = &registros[i];
        printf("\n%dº Lugar - %s | Pontuacao Total: %d\n", i + 1, r->nick, r->pontuacao);
        printf("Resumo -> Acertos: [Fácil: %d | Médio: %d | Difícil: %d] | Erros: %d\n",
               r->acertos.facil, r->acertos.medio, r->acertos.dificil, r->erros);

        printf("  > Perguntas que ACERTOU:\n");
        if (r->qtd_certas == 0) {
            printf("    (Nenhuma)\n");
        } else {
            for (int k = 0; k < r->qtd_certas; k++) {
                const char *enunciado = buscar_enunciado_por_id(r->id_certas[k], banco_completo, nmr_questoes);
                printf("    [OK] ID %s: %s\n", r->id_certas[k], enunciado);
            }
        }

        printf("  > Perguntas que ERROU:\n");
        if (r->qtd_erradas == 0) {
            printf("    (Nenhuma)\n");
        } else {
            for (int k = 0; k < r->qtd_erradas; k++) {
                const char *enunciado = buscar_enunciado_por_id(r->id_erradas[k], banco_completo, nmr_questoes);
                printf("    [X]  ID %s: %s\n", r->id_erradas[k], enunciado);
            }
        }
        printf("------------------------------------------------------\n");
    }

    free(registros);
}