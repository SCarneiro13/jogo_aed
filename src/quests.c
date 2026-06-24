#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "quests.h"
#include "stack.h"

void embaralharPerguntas(tp_pergunta *baralho, int num_questions, tp_baralho *uni1, tp_baralho *uni2, tp_baralho *uni3){
    for (int i = num_questions - 1; i > 0; i--) { // Embaralhando o baralho
        int j = rand() % (i + 1);

        tp_pergunta temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }



    for(int i = 0; i < num_questions; i++){ // Separando nas pilhas das unidades
        switch(baralho[i].unidade){
            case 1:
                push(uni1, baralho[i]);
                break;
            case 2:
                push(uni2, baralho[i]);
                break;
            case 3:
                push(uni3, baralho[i]);
                break;
            default:
                printf("Error: unidade invalida.\n");
                break;
        }
    }

    return;
}



void preparandoPergunta(tp_jogador *j, tp_baralho *uni1, tp_baralho *uni2, tp_baralho *uni3, tp_pergunta *banco_completo, int nmr_questoes){
    int resposta = 0; // Variavel vai ser usada para saber se jogador acertou ou errou.
    
    printf("\n\n\n\n\n");
    
    printf("╔═══════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                       ║\n");
    printf("║ ██████╗ ███████╗██████╗  ██████╗ ██╗   ██╗███╗   ██╗████████╗ █████╗  ║\n");
    printf("║ ██╔══██╗██╔════╝██╔══██╗██╔════╝ ██║   ██║████╗  ██║╚══██╔══╝██╔══██╗ ║\n");
    printf("║ ██████╔╝█████╗  ██████╔╝██║  ███╗██║   ██║██╔██╗ ██║   ██║   ███████║ ║\n");
    printf("║ ██╔═══╝ ██╔══╝  ██╔══██╗██║   ██║██║   ██║██║╚██╗██║   ██║   ██╔══██║ ║\n");
    printf("║ ██║     ███████╗██║  ██║╚██████╔╝╚██████╔╝██║ ╚████║   ██║   ██║  ██║ ║\n");
    printf("║ ╚═╝     ╚══════╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝   ╚═╝   ╚═╝  ╚═╝ ║\n");
    printf("║                                                                       ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════╝\n");

    switch (j->casaAtual.unidade) // Pegando a unidade da casa atual do jogador.
    {
    case 1: // Caso seja a unidade 1.
        resposta = fazerPergunta(uni1, banco_completo, nmr_questoes, 1);
        break;
    case 2: // Caso seja a unidade 2.
        resposta = fazerPergunta(uni2, banco_completo, nmr_questoes, 2);
        break;
    case 3: // Caso seja a unidade 3.
        resposta = fazerPergunta(uni3, banco_completo, nmr_questoes, 3);
        break;
    default: // Caso a unidade não seja valida.
        printf("Error. \nCasa indeterminda");
        break;
    }

    switch (resposta) // Somando na quantidade do acerto/erro
    {
    case 0:
        j->erros++;
        break;
    case 1:
        j->acertos.facil++;
        break;
    case 2:
        j->acertos.medio++;
        break;
    case 3:
        j->acertos.dificil++;
        break;
    }
}



int fazerPergunta(tp_baralho *uni, tp_pergunta *banco_completo, int nmr_questoes, int unidade){

    if(uni->topo <= 0){
        printf("\n[AVISO]: As perguntas da unidade %d acabaram! Reorganizando o baralho de perguntas...\n", unidade);
        reporPerguntas(unidade, banco_completo, nmr_questoes, uni);
    }

    tp_pergunta questao;
    pop(uni, &questao); // Pegando uma questão do topo do baralho.
    int resposta; // Variavel vai ser usada para saber se jogador acertou ou errou.

    printf("\n\nPergunta: %s\n", questao.pergunta); // Fazendo a pergunta.

    for(int i = 0; i < 5; i++){ // Mostrando as alternativas.
        printf("%d) %s\n", i+1, questao.alternativas[i]);
    }

    printf("\nSua resposta (1-5): ");
    fflush(stdout);

    if(scanf("%d", &resposta) != 1){ // Coletando a resposta do jogador
        int ch;

        printf("\nEntrada invalida.\n");
        while((ch = getchar()) != '\n' && ch != EOF);
        return 0;
    }

    printf("\n\n\n\n\n");
    
    printf(".....................................................................\n");
    printf("██████╗ ███████╗███████╗██████╗  ██████╗ ███████╗████████╗ █████╗ ...\n");
    printf("██╔══██╗██╔════╝██╔════╝██╔══██╗██╔═══██╗██╔════╝╚══██╔══╝██╔══██╗...\n");
    printf("██████╔╝█████╗  ███████╗██████╔╝██║   ██║███████╗   ██║   ███████║...\n");
    printf("██╔══██╗██╔══╝  ╚════██║██╔═══╝ ██║   ██║╚════██║   ██║   ██╔══██║...\n");
    printf("██║  ██║███████╗███████║██║     ╚██████╔╝███████║   ██║   ██║  ██║...\n");
    printf("╚═╝  ╚═╝╚══════╝╚══════╝╚═╝      ╚═════╝ ╚══════╝   ╚═╝   ╚═╝  ╚═╝...\n");
    printf(".....................................................................\n");

    if(resposta-1 == questao.resposta){ // Se a resposta for correta.
        printf(" ██████╗ ██████╗ ██████╗ ██████╗ ███████╗████████╗ █████╗ ...........\n");
        printf("██╔════╝██╔═══██╗██╔══██╗██╔══██╗██╔════╝╚══██╔══╝██╔══██╗...........\n");
        printf("██║     ██║   ██║██████╔╝██████╔╝█████╗     ██║   ███████║...........\n");
        printf("██║     ██║   ██║██╔══██╗██╔══██╗██╔══╝     ██║   ██╔══██║...........\n");
        printf("╚██████╗╚██████╔╝██║  ██║██║  ██║███████╗   ██║   ██║  ██║...........\n");
        printf(" ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝   ╚═╝   ╚═╝  ╚═╝...........\n");
        printf(".....................................................................\n");
        printf("██████╗  █████╗ ██████╗  █████╗ ██████╗ ███████╗███╗   ██╗███████╗██╗\n");
        printf("██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔════╝████╗  ██║██╔════╝██║\n");
        printf("██████╔╝███████║██████╔╝███████║██████╔╝█████╗  ██╔██╗ ██║███████╗██║\n");
        printf("██╔═══╝ ██╔══██║██╔══██╗██╔══██║██╔══██╗██╔══╝  ██║╚██╗██║╚════██║╚═╝\n");
        printf("██║     ██║  ██║██║  ██║██║  ██║██████╔╝███████╗██║ ╚████║███████║██╗\n");
        printf("╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚══════╝╚═╝  ╚═══╝╚══════╝╚═╝\n");
        printf(".....................................................................\n");
        while(getchar() != '\n');
        getchar();
        switch (questao.dificuldade) // Verificando a dificuldade da questão.
        {
        case 0: 
            return 1;
            break;
        case 1:
            return 2;
            break;
        case 2:
            return 3;
            break;
        default:
            printf("ERRO! Questão sem dificuldade definida");
            break;
        };
    }else{ // Se a resposta for errada
            printf("███████╗██████╗ ██████╗  █████╗ ██████╗  █████╗ .....................\n");
            printf("██╔════╝██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗.....................\n");
            printf("█████╗  ██████╔╝██████╔╝███████║██║  ██║███████║.....................\n");
            printf("██╔══╝  ██╔══██╗██╔══██╗██╔══██║██║  ██║██╔══██║.....................\n");
            printf("███████╗██║  ██║██║  ██║██║  ██║██████╔╝██║  ██║.....................\n");
            printf("╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝.....................\n");
            printf(".....................................................................\n");
        while(getchar() != '\n');
        getchar();
    }
    return 0;
}

void reporPerguntas (int unidade, tp_pergunta *banco_completo, int nmr_questoes, tp_baralho *uni_atual){
    tp_pergunta aux_vet[MAX_PERGUNTAS];
    int qsts_encontrada = 0; // Quantidade de questões encontradas da unidade que precisa repor

    // Busca as questões da unidade que precisa repor
    for(int i = 0; i < nmr_questoes; i++){
        if(banco_completo[i].unidade == unidade){
            aux_vet[qsts_encontrada] = banco_completo[i];
            qsts_encontrada++;
        }
    }

    // Embaralha as perguntas da unidade encontrada
    for(int i = qsts_encontrada - 1; i > 0; i--){
        int j = rand() % (i + 1); // Escolhe uma posição aleatória do vetor temporário que contém as perguntas

        // Faz a troca entre as perguntas (swap)
        tp_pergunta aux = aux_vet[i];
        aux_vet[i] = aux_vet[j];
        aux_vet[j] = aux;
    }

    // Reseta o topo do pilha e recoloca as perguntas no baralho da unidade que precisava repor
    uni_atual->topo = 0;
    for(int i = 0; i < qsts_encontrada; i++){
        push(uni_atual, aux_vet[i]);
    }
}
