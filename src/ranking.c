#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ranking.h"

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
    int id_certas[MAX_PERG_JOGADOR];
    int qtd_certas;
    int id_erradas[MAX_PERG_JOGADOR];
    int qtd_erradas;
} tp_registro;

int calcular_pontuacao(tp_jogador *j) {
    // Pondera mais a dificuldade maior. Ajuste como preferir.
    return (j->acertos.facil * 10) +
           (j->acertos.medio * 20) +
           (j->acertos.dificil * 30) -
           (j->erros * 5);
}

void salvar_pontuacao(tp_jogador *j) {
    tp_registro reg;
    memset(&reg, 0, sizeof(tp_registro));

    strncpy(reg.nick, j->nick, sizeof(reg.nick) - 1);
    reg.acertos = j->acertos;
    reg.erros = j->erros;
    reg.pontuacao = calcular_pontuacao(j);

    reg.qtd_certas = j->qtd_certas;
    for (int i = 0; i < j->qtd_certas; i++)
        reg.id_certas[i] = j->id_certas[i];

    reg.qtd_erradas = j->qtd_erradas;
    for (int i = 0; i < j->qtd_erradas; i++)
        reg.id_erradas[i] = j->id_erradas[i];

    FILE *f = fopen(ARQUIVO_RANKING, "ab"); // append binário
    if (!f) {
        printf("Erro ao abrir %s para escrita.\n", ARQUIVO_RANKING);
        return;
    }
    fwrite(&reg, sizeof(tp_registro), 1, f);
    fclose(f);
}

// Comparador para qsort: maior pontuação primeiro.
static int comparar_registros(const void *a, const void *b) {
    const tp_registro *ra = (const tp_registro *)a;
    const tp_registro *rb = (const tp_registro *)b;
    return rb->pontuacao - ra->pontuacao;
}

void exibir_ranking(tp_pergunta *banco_completo, int nmr_questoes) {
    FILE *f = fopen(ARQUIVO_RANKING, "rb");
    if (!f) {
        printf("\nAinda não há partidas registradas.\n");
        return;
    }

    // Descobre quantos registros existem.
    fseek(f, 0, SEEK_END);
    long tamanho = ftell(f);
    fseek(f, 0, SEEK_SET);
    int total = tamanho / sizeof(tp_registro);

    if (total == 0) {
        printf("\nAinda não há partidas registradas.\n");
        fclose(f);
        return;
    }

    tp_registro *registros = malloc(total * sizeof(tp_registro));
    fread(registros, sizeof(tp_registro), total, f);
    fclose(f);

    qsort(registros, total, sizeof(tp_registro), comparar_registros);

    printf("\n===============================\n");
    printf("           RANKING\n");
    printf("===============================\n");

    for (int i = 0; i < total; i++) {
        tp_registro *r = &registros[i];
        printf("\n%dº lugar - %s | Pontuação: %d\n", i + 1, r->nick, r->pontuacao);
        printf("Acertos: [F: %d | M: %d | D: %d]  Erros: %d\n",
               r->acertos.facil, r->acertos.medio, r->acertos.dificil, r->erros);

        printf("  Perguntas que acertou:\n");
        if (r->qtd_certas == 0) printf("    (nenhuma)\n");
        for (int k = 0; k < r->qtd_certas; k++) {
            int idx = r->id_certas[k];
            if (idx >= 0 && idx < nmr_questoes)
                printf("    [OK] %s\n", banco_completo[idx].pergunta);
        }

        printf("  Perguntas que errou:\n");
        if (r->qtd_erradas == 0) printf("    (nenhuma)\n");
        for (int k = 0; k < r->qtd_erradas; k++) {
            int idx = r->id_erradas[k];
            if (idx >= 0 && idx < nmr_questoes)
                printf("    [X]  %s\n", banco_completo[idx].pergunta);
        }
    }

    free(registros);
    printf("\n===============================\n");
}
