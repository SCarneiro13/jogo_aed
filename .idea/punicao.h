#ifndef PUNICAO_H
#define PUNICAO_H

#include <stdio.h>

// Definição das constantes para os tipos de punição
#define SEM_PUNICAO         0
#define VOLTAR_CASAS        1
#define PERDER_TURNO        2
#define REINICIAR_UNIDADE   3

/**
 * Função apenas informativa/executiva para traduzir o ID da punição 
 * em uma mensagem textual ou lógica para o seu jogo.
 * * @param id_punicao O ID armazenado na casa do tabuleiro (nova_casa.punicao)
 */
void aplicar_punicao(int id_punicao) {
    switch (id_punicao) {
        case VOLTAR_CASAS:
            printf("[PUNIÇÃO] Azar! O jogador deve voltar 2 casas.\n");
            // jogador->posicao -= 2;
            break;
            
        case PERDER_TURNO:
            printf("[PUNIÇÃO] Que pena! O jogador perdeu o próximo turno.\n");
            // jogador->pula_vez = 1;
            break;
            
        case REINICIAR_UNIDADE:
            printf("[PUNIÇÃO] Alerta crítico! O jogador deve voltar para o início desta unidade.\n");
            // Se unidade == 1 -> posicao = 1;
            // Se unidade == 2 -> posicao = 16;
            // Se unidade == 3 -> posicao = 31;
            break;
            
        default:
            // Caso seja SEM_PUNICAO (0) ou qualquer outro valor inesperado
            break;
    }
}

#endif // PUNICAO_H
