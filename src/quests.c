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
        resposta = fazerPergunta(uni1, banco_completo, nmr_questoes, 1, j->nick);
        break;
    case 2: // Caso seja a unidade 2.
        resposta = fazerPergunta(uni2, banco_completo, nmr_questoes, 2, j->nick);
        break;
    case 3: // Caso seja a unidade 3.
        resposta = fazerPergunta(uni3, banco_completo, nmr_questoes, 3, j->nick);
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



int fazerPergunta(tp_baralho *uni, tp_pergunta *banco_completo, int nmr_questoes, int unidade, char *nome_jogador){

    if(uni->topo <= 0){
        printf("\n[AVISO]: As perguntas da unidade %d acabaram! Reorganizando o baralho de perguntas...\n", unidade);
        reporPerguntas(unidade, banco_completo, nmr_questoes, uni);
    
        return fazerPergunta(uni, banco_completo, nmr_questoes, unidade, nome_jogador);
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

        salvarHistoricoResposta(nome_jogador, questao, -1, "Errou");
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

        salvarHistoricoResposta(nome_jogador, questao, resposta-1, "Acertou");

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
        
        salvarHistoricoResposta(nome_jogador, questao, resposta-1, "Errou");

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



void salvarHistoricoResposta (char nomeJogador[], tp_pergunta p, int respJogador, char resultado[]){
    FILE *arquivo = fopen("historico_respostas.csv", "a");

    if(arquivo == NULL){
        printf("ERRO! Nao foi possivel criar o arquivo de historico de respostas.\n");
        return;
    }
    
    // Covertendo as dificuldades que são int para char
    char dificuldade[20];
    if(p.dificuldade == 0) sprintf(dificuldade, "Facil");
    else if(p.dificuldade == 1) sprintf(dificuldade, "Medio");
    else sprintf(dificuldade, "Dificil");

    // Convertendo as respostas que são int para char
    char resp_jogador = 'A' + respJogador;
    char resp_correta = 'A' + p.resposta;

    // Dado fixo do semestre
    char turma[] = "AED-2026.1-M";

    fprintf(arquivo, "%s;%s;%s;%d;%s;%s;%s;%c;%c;%s\n", turma, nomeJogador, p.id, p.unidade, p.tema, p.subtema, dificuldade, resp_jogador, resp_correta, resultado);
    fclose(arquivo);

}



void gerarArquivoReferencia (tp_pergunta *banco_completo, int nmr_questoes){
    FILE *arquivo = fopen("perguntas.csv", "w");

    if(arquivo == NULL){
        printf("ERRO! Nao foi possivel criar o arquivo de referncia de pergunta.\n");
        return;
    }

    fprintf(arquivo, "id_pergunta;unidade;tema;dificuldade;enunciado\n");

    for(int i = 0; i < nmr_questoes; i++){

        char dificuldade[20];
        if(banco_completo[i].dificuldade == 0) sprintf(dificuldade, "Facil");
        else if(banco_completo[i].dificuldade == 1) sprintf(dificuldade, "Medio");
        else sprintf(dificuldade, "Dificil");

        fprintf(arquivo, "%s;%d;%s;%s;%s\n", banco_completo[i].id, banco_completo[i].unidade, banco_completo[i].tema, dificuldade, banco_completo[i].pergunta);
    }

    fclose(arquivo);
    printf("AVISO: Arquivo 'perguntas.csv' de referencia gerado com sucesso");
}