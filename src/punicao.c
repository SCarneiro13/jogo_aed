#include "punicao.h"

/**
 * Implementação da função que traduz o ID da punição 
 * em uma ação ou mensagem textual no console.
 */
void aplicar_punicao(int id_punicao) {
    switch (id_punicao) {
        case VOLTAR_CASAS:
            printf("[PUNICAO] Azar! O jogador deve voltar 2 casas.\n");
            break;
            
        case PERDER_TURNO:
            printf("[PUNICAO] Que pena! O jogador perdeu o proximo turno.\n");
            break;
            
        case REINICIAR_UNIDADE:
            printf("[PUNICAO] Alerta critico! O jogador deve voltar para o inicio desta unidade.\n");
            break;
            
        default:
            // Caso seja SEM_PUNICAO (0) ou qualquer outro valor, nao faz nada
            break;
    }
}
