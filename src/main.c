#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "quests.h"
#include "stack.h"
#include "queue.h"
#include "user.h"

int main(){

/*INICIALIZAÇÃO BASE DO JOGO*/

    srand(time(NULL)); // Comando para randomizar e embaralhar o baralho.

/*PREPARANDO BARALHOS DE CADA UNIDADE*/

    tp_pergunta baralho[MAX_PERGUNTAS] = { // Baralho com as perguntas.
    {
    1,
    0,
    "Sobre tipos primitivos e manipulacao de caracteres em C, assinale a alternativa correta: Qual das atribuicoes e semanticamente correta para uma variavel do tipo char?",
    {"char c = \"V\";", "char c = 'V';", "char c = strlen(\"V\");", "char c = &\"V\";", "char c = V;"},
    1 // b
},
{
    1,
    0,
    "Em relacao ao comportamento da estrutura de dados Pilha (Stack), assinale a alternativa correta:",
    {"FIFO - o primeiro elemento inserido e o primeiro a ser removido", "LILO - o ultimo elemento inserido e o ultimo a ser removido", "LIFO - o ultimo elemento inserido e o primeiro a ser removido", "Acesso direto por indice (random access)", "Remocao baseada em prioridade"},
    2 // c
},
{
    1,
    0,
    "Em uma implementacao estatica de fila utilizando vetor, a funcao inicializaFila(tp_fila *f) tem como principal objetivo:",
    {"Liberar a memoria ocupada pela fila", "Configurar os indices de controle para representar uma fila vazia", "Exibir os elementos armazenados", "Alocar memoria dinamicamente", "Ordenar os elementos da fila"},
    1 // b
},
{
    1,
    1,
    "Considere uma pilha inicialmente vazia. Apos executar a sequencia: push(&p, 'A'); push(&p, 'B'); pop(&p, &e); push(&p, 'C'); Qual sera o elemento no topo da pilha ao final?",
    {"'A'", "'B'", "'C'", "'e'", "Pilha vazia"},
    2 // c
},
{
    1,
    1,
    "Analise o trecho: for (int i = 0; i < strlen(f); i++) - Sabendo que f e do tipo tp_fila *, identifique o problema:",
    {"Declaracao de variavel no for e invalida em C", "Uso incorreto de strlen, pois espera char *", "Falta do operador & em f", "Comparacao deveria ser <=", "Indice deveria iniciar em 1"},
    1 // b
},
{
    1,
    1,
    "Ao tentar agrupar elementos iguais em uma fila (por exemplo, todos os 'V' juntos), utilizando apenas uma pilha auxiliar, qual estrategia e mais adequada?",
    {"Utilizar strlen para contar elementos", "Transferir todos os elementos para a pilha e devolver diretamente", "Rotacionar a fila, reinserindo elementos nao desejados no final", "Nao e possivel com apenas uma pilha", "Redimensionar a fila com sizeof"},
    2 // c
},
{
    1,
    2,
    "Considere a funcao int removeFila(tp_fila *f, tp_item *e); e as variaveis: tp_fila fila; tp_item x; tp_item *px = &x; Assinale a alternativa em que as duas chamadas estejam coerentes:",
    {"removeFila(&fila, &x); e removeFila(&fila, px);", "removeFila(fila, &x); e removeFila(&fila, x);", "removeFila(&fila, x); e removeFila(fila, px);", "removeFila(fila, x); e removeFila(&fila, px);", "removeFila(&fila, &px); e removeFila(fila, &x);"},
    0 // a
},
{
    1,
    2,
    "Dada a funcao void imprimeFila(tp_fila f) que recebe a fila por valor e utiliza removeFila, o que acontece com a fila original apos a chamada?",
    {"Sera esvaziada", "Permanecera inalterada", "Ocorrera erro de compilacao", "Sera invertida", "Perdera apenas o primeiro elemento"},
    1 // b
},
{
    1,
    2,
    "Ao utilizar uma pilha como estrutura auxiliar para reorganizar uma fila, qual limitacao fundamental deve ser considerada?",
    {"Pilhas nao armazenam caracteres", "A ordem dos elementos e invertida ao retornar da pilha", "A fila nao pode mais ser acessada", "Necessidade obrigatoria de alocacao dinamica", "O topo da pilha representa o primeiro elemento inserido"},
    1 // b
}
};

tp_baralho pilha_unidade1, pilha_unidade2, pilha_unidade3; // Baralho de cada unidade
inicializa_pilha(&pilha_unidade1);
inicializa_pilha(&pilha_unidade2);
inicializa_pilha(&pilha_unidade3);

/*CONTANDO QUANTIDADE DE PERGUNTAS*/
int num_questions = 0;
for(int i = 0; i < MAX_PERGUNTAS; i++){
    if(baralho[i].unidade != 0){
        num_questions++;
    }
}

embaralharPerguntas(baralho, num_questions, &pilha_unidade1, &pilha_unidade2, &pilha_unidade3); // Função para embaralhar, está definida em quests.h e codada em quests.c

/*PREPARANDO PARA RECEBER USUARIOS*/

int qtdJog;
tp_fila fila;
inicializaFila(&fila);

/*INICIAÇÃO PROVISÓRIA DO JOGO*/

printf("BEM VINDO AO JOGO!\n\n");

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

    while(!pilha_vazia(&pilha_unidade1)){
        tp_pergunta questao;
        pop(&pilha_unidade1, &questao);
        Jogador jogador;
        removeFila(&fila, &jogador);
        printf("\n--- Pergunta para %s ---\n", jogador.nick);
        printf("Pergunta: %s\n", questao.pergunta);
        for(int j = 0; j < 5; j++){
            printf("%d) %s\n", j+1, questao.alternativas[j]);
        }
        int resposta;
        printf("Sua resposta (1-5): ");
        scanf("%d", &resposta);
        if(resposta - 1 == questao.resposta){
            printf("Resposta correta!\n");
            if(questao.dificuldade == 0) jogador.acertos.facil++;
            else if(questao.dificuldade == 1) jogador.acertos.medio++;
            else jogador.acertos.dificil++;
        } else {
            printf("Resposta incorreta. A resposta correta era: %s\n", questao.alternativas[questao.resposta] + 1);
            jogador.erros++;
        }
        insereFila(&fila, jogador);
    }

    while(!filaVazia(&fila)){
        Jogador j;
        removeFila(&fila, &j);
        printf("\n--- Resultado de %s ---\n", j.nick);
        printf("Acertos fáceis: %d\n", j.acertos.facil);
        printf("Acertos médios: %d\n", j.acertos.medio);
        printf("Acertos difíceis: %d\n", j.acertos.dificil);
        printf("Erros: %d\n", j.erros);
    }


    return 0;
}