#ifndef BARALHO_H
#define BARALHO_H

#include "quests.h"

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

#endif