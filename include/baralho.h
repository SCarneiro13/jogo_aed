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
},
{
    2,
    1,
    "Sobre a alocação de memória em C, qual a principal diferença entre a alocação estática (vetores comuns) e a dinâmica (malloc)?",
    {"A estática ocorre em tempo de execução, a dinâmica em tempo de compilação", "A estática é feita na Stack, a dinâmica na Heap", "A dinâmica permite definir o tamanho da memória durante a execução do programa", "A memória alocada estaticamente deve ser liberada com free()", "Vetores estáticos não possuem tamanho fixo"},
    2 // c
},
{
    2,
    2,
    "Em uma lista simplesmente encadeada, para remover o primeiro nó da lista (denotado por 'L'), qual a sequência lógica correta?",
    {"L = L->prox; free(L);", "tp_no *aux = L; L = L->prox; free(aux);", "free(L); L = L->prox;", "L->prox = NULL; free(L);", "tp_no *aux = L->prox; free(L); L = aux->prox;"},
    1 // b
},
{
    2,
    2,
    "Considere uma lista encadeada onde cada nó tem um ponteiro 'prox'. O que acontece se executarmos 'atual->prox = atual->prox->prox' em uma lista com 3 elementos, sendo 'atual' o primeiro elemento?",
    {"O segundo elemento é removido da encadeação, mas permanece na memória (gera 'memory leak' se não houver outro ponteiro)", "A lista é invertida completamente", "Ocorre um erro de segmentação (Segmentation Fault) obrigatoriamente", "O primeiro elemento passa a apontar para si mesmo", "O terceiro elemento é deletado da memória automaticamente"},
    0 // a
},
{
    2,
    1,
    "Sobre o algoritmo Quick Sort, qual situação leva ao pior caso de desempenho quando o pivô escolhido é sempre o primeiro elemento?",
    {"Vetor com elementos aleatórios", "Vetor parcialmente ordenado", "Vetor já ordenado", "Vetor com números negativos", "Vetor com tamanho par"},
    2 // c
},
{
    2,
    2,
    "Sobre algoritmos de ordenação estáveis, qual alternativa descreve corretamente sua principal característica?",
    {"Executam sempre em O(n log n)", "Mantêm a ordem relativa de elementos com valores iguais", "Utilizam apenas estruturas lineares", "Não realizam trocas de elementos", "Funcionam apenas com vetores ordenados"},
    1 // b
},
{
    2,
    2,
    "Considere um Merge Sort aplicado em um vetor de tamanho n. Qual é a principal razão para sua complexidade ser O(n log n)?",
    {"Porque o vetor é percorrido apenas uma vez", "Porque cada divisão elimina metade dos elementos definitivamente", "Porque o algoritmo divide o vetor em log n níveis e realiza O(n) operações em cada nível", "Porque o algoritmo utiliza apenas trocas adjacentes", "Porque o Merge Sort evita comparações entre elementos"},
    2 // c
},
{
2,
1,
"Em uma estrutura de dados do tipo Fila implementada por meio de uma lista encadeada simples, em qual extremidade devem ocorrer as inserções e as remoções para garantir uma eficiência de tempo constante O(1)?",
{"As inserções ocorrem no início da lista e as remoções ocorrem no fim da lista", "As inserções ocorrem no fim da lista e as remoções ocorrem no início da lista", "Tanto as inserções quanto as remoções devem ocorrer no início da lista", "Tanto as inserções quanto as remoções devem ocorrer no fim da lista", "As inserções e remoções podem ser feitas em qualquer extremidade aleatoriamente"},
1 // b
},
{
2,
2,
"O algoritmo de busca binária possui uma alta eficiência computacional. Qual é a pré-condição obrigatória que a estrutura de dados deve atender para que este algoritmo funcione corretamente, e qual é a sua complexidade de tempo no pior caso?",
{"Os dados devem estar indexados em posições contíguas e a complexidade é O(n log n)", "Os dados devem estar indexados e a complexidade de pior caso é O(n)", "Os dados devem estar obrigatoriamente ordenados e a complexidade de pior caso é O(log n)", "Os dados podem estar em qualquer ordem e a complexidade é O(log n)", "Os dados devem estar estruturados em uma árvore binária e a complexidade é O(n^2)"},
2 // c
},
{
2,
2,
"Considere que você deseja aplicar a lógica teórica da busca binária para encontrar um elemento em uma lista simplesmente encadeada (linear e não indexada) que já se encontra perfeitamente ordenada. Qual é a complexidade de tempo no pior caso para realizar essa busca?",
{"A complexidade será O(log n), pois a lógica de divisões sucessivas da busca binária é mantida intacta", "A complexidade será O(n), pois o acesso ao elemento central a cada etapa exige o percorrimento sequencial dos nós", "A complexidade será O(n log n), devido à multiplicação do fator de divisão pelo tamanho total da lista encadeada", "A complexidade será O(1), porque a ordenação perfeita anula a necessidade de saltos na estrutura de nós", "A operação é impossível de ser calculada, gerando um erro de estouro de pilha (stack overflow)"},
1 // b
}
};

#endif
