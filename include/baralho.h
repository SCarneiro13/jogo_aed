#ifndef BARALHO_H
#define BARALHO_H

#include "quests.h"

// Baralho estruturado com as informacoes completas de ID, Tema, Subtema e Dificuldade
tp_pergunta baralho[MAX_PERGUNTAS] = {
    {
        "P001", 
        1,
        0,
        "Ponteiros", 
        "Tipos Primitivos",
        "Sobre tipos primitivos e manipulacao de caracteres em C, assinale a alternativa correta: Qual das atribuicoes e semanticamente correta para uma variavel do tipo char?",
        {"char c = \"V\";", "char c = 'V';", "char c = strlen(\"V\");", "char c = &\"V\";", "char c = V;"},
        1 // b
    },
    {
        "P002", 
        1, 
        0, 
        "Pilha", 
        "LIFO",
        "Em relacao ao comportamento da estrutura de dados Pilha (Stack), assinale a alternativa correta:",
        {"FIFO - o primeiro elemento inserido e o primeiro a ser removido", "LILO - o ultimo elemento inserido e o ultimo a ser removido", "LIFO - o ultimo elemento inserido e o primeiro a ser removido", "Acesso direto por indice (random access)", "Remocao baseada em prioridade"},
        2 // c
    },
    {
        "P003", 
        1, 
        0, 
        "Fila", 
        "Inicializacao",
        "Em uma implementacao estatica de fila utilizando vetor, a funcao inicializaFila(tp_fila *f) tem como principal objetivo:",
        {"Liberar a memoria ocupada pela fila", "Configurar os indices de controle para representar uma fila vazia", "Exibir os elementos armazenados", "Alocar memoria dinamicamente", "Ordenar os elementos da fila"},
        1 // b
    },
    {
        "P004",
        1, 
        1, 
        "Pilha", 
        "Operacoes",
        "Considere uma pilha inicialmente vazia. Apos executar a sequencia: push(&p, 'A'); push(&p, 'B'); pop(&p, &e); push(&p, 'C'); Qual sera o elemento no topo da pilha ao final?",
        {"'A'", "'B'", "'C'", "'e'", "Pilha vazia"},
        2 // c
    },
    {
        "P005", 
        1, 
        1, 
        "Fila", 
        "Erros Comuns",
        "Analise o trecho: for (int i = 0; i < strlen(f); i++) - Sabendo que f e do tipo tp_fila *, identifique o problema:",
        {"Declaracao de variavel no for e invalida em C", "Uso incorreto de strlen, pois espera char *", "Falta do operador & em f", "Comparacao deveria ser <=", "Indice deveria iniciar em 1"},
        1 // b
    },
    {
        "P006", 
        1, 
        1, 
        "Fila", 
        "Algoritmos",
        "Ao tentar agrupar elements iguais em uma fila (por exemplo, todos os 'V' juntos), utilizando apenas uma pilha auxiliar, qual estrategia e mais adequada?",
        {"Utilizar strlen para counting elementos", "Transferir todos os elementos para a pilha e devolver diretamente", "Rotacionar a fila, reinserindo elementos nao desejados no final", "Nao e possivel com apenas uma pilha", "Redimensionar a fila com sizeof"},
        2 // c
    },
    {
        "P007", 
        1, 
        2, 
        "Fila", 
        "Parametros",
        "Considere a funcao int removeFila(tp_fila *f, tp_item *e); e as variaveis: tp_fila fila; tp_item x; tp_item *px = &x; Assinale a alternativa em que as duas chamadas estejam coerentes:",
        {"removeFila(&fila, &x); e removeFila(&fila, px);", "removeFila(fila, &x); e removeFila(&fila, x);", "removeFila(&fila, x); e removeFila(fila, px);", "removeFila(fila, x); e removeFila(&fila, px);", "removeFila(&fila, &px); e removeFila(fila, &x);"},
        0 // a
    },
    {
        "P008", 
        1, 
        2, 
        "Fila", 
        "Passagem por Valor",
        "Dada a funcao void imprimeFila(tp_fila f) que recebe a fila por valor e utiliza removeFila, o que acontece com a fila original apos a chamada?",
        {"Sera esvaziada", "Permanecera inalterada", "Ocorrera erro de compilacao", "Sera invertida", "Perdera apenas o primeiro elemento"},
        1 // b
    },
    {
        "P009", 
        1, 
        2, 
        "Pilha", 
        "Estruturas Auxiliares",
        "Ao utilizar uma pilha como estrutura auxiliar para reorganizar uma fila, qual limitacao fundamental deve ser considerada?",
        {"Pilhas nao armazenam caracteres", "A ordem dos elementos e invertida ao retornar da pilha", "A fila nao pode mais ser acessada", "Necessidade obrigatoria de alocacao dinamica", "O topo da pilha representa o primeiro elemento inserido"},
        1 // b
    },
    {
        "P010", 
        2, 
        1, 
        "Alocacao Dinamica", 
        "Malloc vs Estatico",
        "Sobre a alocação de memória em C, qual a principal diferença entre a alocação estática (vetores comuns) e a dinâmica (malloc)?",
        {"A estática ocorre em tempo de execução, a dinâmica em tempo de compilação", "A estática é feita na Stack, a dinâmica na Heap", "A dinâmica permite definir o tamanho da memória durante a execução do programa", "A memória alocada estaticamente deve ser liberada com free()", "Vetores estáticos não possuem tamanho fixo"},
        2 // c
    },
    {
        "P011", 
        2, 
        2, 
        "Lista Encadeada", 
        "Remocao",
        "Em uma lista simplesmente encadeada, para remover o primeiro nó da lista (denotado por 'L'), qual a sequência lógica correta?",
        {"L = L->prox; free(L);", "tp_no *aux = L; L = L->prox; free(aux);", "free(L); L = L->prox;", "L->prox = NULL; free(L);", "tp_no *aux = L->prox; free(L); L = aux->prox;"},
        1 // b
    },
    {
        "P012", 
        2, 
        2, 
        "Lista Encadeada", 
        "Memory Leak",
        "Considere uma lista encadeada onde cada nó tem um ponteiro 'prox'. O que acontece se executarmos 'atual->prox = atual->prox->prox' em uma lista com 3 elementos, sendo 'atual' o primeiro elemento?",
        {"O segundo elemento é removido da encadeação, mas permanece na memória (gera 'memory leak' se não houver outro ponteiro)", "A lista é invertida completamente", "Ocorre um erro de segmentação (Segmentation Fault) obrigatoriamente", "O primeiro elemento passa a apontar para si mesmo", "O terceiro elemento é deletado da memória automaticamente"},
        0 // a
    },
    {
        "P013", 
        2, 
        1, 
        "Ordenacao", 
        "Quick Sort",
        "Sobre o algoritmo Quick Sort, qual situação leva ao pior caso de desempenho quando o pivô escolhido é sempre o primeiro elemento?",
        {"Vetor com elementos aleatórios", "Vetor parcialmente ordenado", "Vetor já ordenado", "Vetor com números negativos", "Vetor com tamanho par"},
        2 // c
    },
    {
        "P014", 
        2, 
        2, 
        "Ordenacao", 
        "Estabilidade",
        "Sobre algoritmos de ordenação estáveis, qual alternativa descreve corretamente sua principal characteristic?",
        {"Executam sempre em O(n log n)", "Mantêm a ordem relativa de elementos com valores iguais", "Utilizam apenas estruturas lineares", "Não realizam trocas de elementos", "Funcionam apenas com vetores ordenados"},
        1 // b
    },
    {
        "P015", 
        2, 
        2, 
        "Ordenacao", 
        "Merge Sort",
        "Considere um Merge Sort aplicado em um vetor de tamanho n. Qual é a principal razão para sua complexidade ser O(n log n)?",
        {"Because o vetor é percorrido apenas uma vez", "Porque cada divisão elimina metade dos elementos definitivamente", "Porque o algoritmo divide o vetor em log n níveis e realiza O(n) operações em cada nível", "Porque o algoritmo utiliza apenas trocas adjacentes", "Porque o Merge Sort evita comparações entre elementos"},
        2 // c
    },
    {
        "P016", 
        2, 
        1, 
        "Fila", 
        "Lista Encadeada",
        "Em uma estrutura de dados do tipo Fila implementada por meio de uma lista encadeada simples, em qual extremidade devem ocorrer as inserções e as remoções para garantir uma eficiência de tempo constante O(1)?",
        {"As inserções ocorrem no início da lista e as remoções ocorrem no fim da lista", "As inserções ocorrem no fim da lista e as remoções ocorrem no início da lista", "Tanto as inserções quanto as remoções devem ocorrer no início da lista", "Tanto as inserções quanto as remoções devem ocorrer no fim da lista", "As inserções e remoções podem ser feitas em qualquer extremidade aleatoriamente"},
        1 // b
    },
    {
        "P017", 
        2, 
        2, 
        "Busca", 
        "Busca Binaria",
        "O algoritmo de busca binária possui uma alta eficiência computacional. Qual é a pré-condição obrigatória que a estrutura de dados deve atender para que este algoritmo funcione corretamente, e qual é a sua complexidade de tempo no pior caso?",
        {"Os dados devem estar indexados em posições contíguas e a complexidade é O(n log n)", "Os dados devem estar indexados e a complexidade de pior caso é O(n)", "Os dados devem estar obrigatoriamente ordenados e a complexidade de pior caso é O(log n)", "Os dados podem estar em qualquer ordem e a complexidade é O(log n)", "Os dados devem estar estruturados em uma árvore binária e a complexidade é O(n^2)"},
        2 // c
    },
    {
        "P018", 
        2, 
        2, 
        "Busca", 
        "Busca em Lista",
        "Considere que você deseja aplicar a lógica teórica da busca binária para encontrar um elemento em uma lista simplesmente encadeada (linear e não indexada) que já se encontra perfeitamente ordenada. Qual é a complexidade de tempo no pior caso para realizar essa busca?",
        {"A complexidade será O(log n), pois a lógica de divisões sucessivas da busca binária é mantida intacta", "A complexidade será O(n), pois o acesso ao elemento central a cada etapa exige o percorrimento sequencial dos nós", "A complexidade será O(n log n), devido à multiplicação do fator de divisão pelo tamanho total da lista encadeada", "A complexidade será O(1), porque a ordenação perfeita anula a necessidade de saltos na estrutura de nós", "A operação é impossível de ser calculada, gerando um erro de estouro de pilha (stack overflow)"},
        1 // b
    },
    {
        "P019", 
        3, 
        1, 
        "Busca", 
        "Arvore Trie",
        "Uma árvore Trie (ou árvore de prefixos) é uma estrutura de dados de busca baseada em chaves que frequentemente representam strings. Qual é a principal característica arquitetural de uma Trie padrão que a diferencia de uma Árvore Binária de Busca tradicional?",
        {"Cada nó possui obrigatoriamente no máximo dois filhos e armazena chaves numéricas inteiras de forma rigidamente balanceada", "Os nós não armazenam a chave completa; em vez disso, a chave é definida pela posição do nó na árvore, baseada no caminho percorrido a partir da raiz", "Os elementos são organizados por meio de funções de espalhamento (hash) diretamente nas páginas de memória folha da árvore", "Ela elimina completamente a necessidade de ponteiros ou referências de memória, utilizando exclusivamente indexação sequencial contígua", "A busca em uma Trie requer que a árvore esteja completamente balanceada por altura, gerando rotações complexas a cada inserção"},
        1 // b
    },
    {
        "P020", 
        3, 
        2, 
        "Busca", 
        "Arvore PATRICIA",
        "A árvore PATRICIA (Practical Algorithm to Retrieve Information Coded in Alphanumeric) é uma variação otimizada da árvore Trie padrão. Qual modificação estrutural a árvore PATRICIA introduz para economizar espaço de memória?",
        {"Ela substitui todos os nós internos por listas encadeadas circulares, removendo completamente o conceito de hierarquia de prefixos", "Ela armazena os dados em uma tabela linear estática e utiliza busca binária recursiva para simular a correspondência dos prefixos", "Ela realiza a compressão de caminhos (path compression), agrupando nós internos sequenciais que possuem apenas um único filho em um único nó com rótulo de múltiplos caracteres", "Ela restringe o alfabeto estritamente a valores booleanos (0 e 1), forçando qualquer tipo de chave a se comportar como um número inteiro de 32 bits", "Ela transforma a árvore em um grafo direcionado acíclico onde nenhum nó pode ter mais do que um único descendente direto"},
        2 // c
    },
    {
        "P021", 
        3, 
        3, 
        "Busca", 
        "Trie vs PATRICIA",
        "Considere o cenário de armazenar um dicionário esparso contendo poucas palavras, porém cada palavra possui um comprimento extremamente longo (L). Se compararmos o desempenho e o uso de memória entre uma Trie padrão e uma Árvore PATRICIA para esse cenário, qual será o comportamento correto das estruturas?",
        {"Ambas gastarão exatamente a mesma quantidade de nós, pois o comprimento longo exige a mesma alocação de caracteres", "A busca na Árvore PATRICIA passará a ser O(N), onde N é o número total de palavras, tornando-a muito mais lenta que a Trie padrão", "A Árvore PATRICIA falhará ao processar chaves longas devido ao limite teórico rígido de caracteres que uma única string de nó compactado pode suportar", "A Trie padrão sofrerá com alto desperdício de memória criando O(L) nós por palavra, enquanto a Árvore PATRICIA limitará o número total de nós internos ao número de chaves e ramificações, garantindo maior eficiência de espaço", "A Trie padrão otimizará o espaço automaticamente reduzindo o comprimento L para um valor constante, enquanto a PATRICIA duplicará os nós de forma exponencial"},
        3 // d
    },
    {
        "P022", 
        3, 
        1, 
        "Arvore Binaria", 
        "Percorrimento",
        "Ao realizar um percorrimento (travessia) em uma Árvore Binária de Busca (BST), qual estratégia de visitação de nós garante que as chaves sejam acessadas em ordem estritamente crescente?",
        {"Percorrimento em pré-ordem (pre-order)", "Percorrimento em pós-ordem (post-order)", "Percorrimento em largura (BFS)", "Percorrimento em ordem simétrica ou em-ordem (in-order)", "Percorrimento por profundidade aleatório"},
        3 // d
    },
    {
        "P023", 
        3, 
        2, 
        "Arvore AVL", 
        "Balanceamento",
        "Uma árvore AVL é uma árvore binária de busca auto-balanceada. Como é definido o fator de balanceamento de um nó nesta estrutura e qual medida é tomada caso esse fator se torne inválido após uma inserção?",
        {"O fator é a diferença entre o número total de nós à esquerda e à direita, e a árvore deve ser totalmente reconstruída se o fator sair do intervalo [-1, 1]", "O fator é a diferença entre as alturas das subárvores esquerda e direita, devendo estar no intervalo [-1, 1]; se violado, aplicam-se rotações (simples ou duplas) para rebalancear a árvore", "O fator representa a profundidade máxima da árvore a partir da raiz, e qualquer variação exige a inversão completa dos ponteiros dos nós", "O fator é a soma das alturas de ambas as subárvores, e sua violação causa a exclusão automática do último nó inserido", "O fator é devidamente determinado pela quantidade de nós folha da árvore, demandando uma busca linear para readequação dos ponteiros"},
        1 // b
    },
    {
        "P024", 
        3, 
        3, 
        "Arvore AVL", 
        "BST vs AVL",
        "Se inserirmos uma sequência de n elementos já ordenados de forma crescente (por exemplo: 1, 2, 3, ..., n) em uma Árvore Binária de Busca (BST) padrão inicialmente vazia e em uma Árvore AVL também inicialmente vazia, qual será o impacto na complexidade de tempo do pior caso para a operação de busca em cada uma delas?",
        {"A busca na BST padrão será O(log n) e na Árvore AVL será O(n), pois as rotações da AVL prejudicam o desempenho com dados ordenados", "Ambas as árvores manterão a complexidade de busca em O(log n), já que a ordenação prévia é a situação ideal para estruturas de árvores", "A BST padrão degenerará em uma estrutura linear (similar a uma lista), resultando em busca O(n), enquanto a Árvore AVL aplicará rotações para manter a altura controlada, garantindo busca O(log n)", "Ambas as árvores sofrerão uma falha crítica de estouro de pilha (stack overflow) devido à impossibilidade de processar elementos ordenados", "A BST padrão terá tempo de busca O(1) devido ao encadeamento simples dos nós e a Árvore AVL terá tempo de busca O(n log n)"},
        2 // c
    },
    {
        "P025", 
        3, 
        1, 
        "Complexidade", 
        "Tabela Hash",
        "Qual é a complexidade de tempo esperada (caso médio) para as operações de inserção, remoção e busca de um elemento em uma Tabela Hash bem dimensionada e que utiliza uma função de espalhamento eficiente?",
        {"O(n)", "O(1)", "O(log n)", "O(n log n)", "O(n^2)"},
        1 // b
    },
    {
        "P026", 
        3, 
        2, 
        "Complexidade", 
        "Sondagem Linear",
        "No método de tratamento de colisões por endereçamento aberto conhecido como Sondagem Linear (Linear Probing), qual fenômeno negativo tende a ocorrer conforme o fator de carga da tabela aumenta, prejudicando severamente o desempenho das operações de busca?",
        {"Fragmentação externa de memória por desalocação estática", "Dispersão caótica de ponteiros, que invalida o cálculo matemático do índice original", "Agrupamento primário (primary clustering), onde chaves colididas formam longos blocos sequenciais de posições ocupadas no vetor", "Encadeamento infinito de subchaves dentro do mesmo slot", "Transformação automática e obrigatória da tabela em uma árvore AVL de profundidade n"},
        2 // c
    },
    {
        "P027", 
        3, 
        3, 
        "Complexidade", 
        "Separate Chaining",
        "Em uma implementação de Tabela Hash que utiliza encadeamento externo (Separate Chaining) por meio de listas encadeadas simples, qual é a complexidade de tempo no pior caso absoluto para a operação de busca e qual estratégia moderna de otimização estrutural é adotada para mitigar esse cenário específico?",
        {"A complexidade é O(1) e a estratégia consiste na aplicação de uma segunda função hash (double hashing) para fundir as listas de buckets diferentes", "A complexidade é O(log n) e a estratégia consiste na conversão automática da tabela inteira em um vetor dinâmico contíguo e ordenado", "A complexidade é O(n^2) e a estratégia exige a reinicialização completa da tabela e o descarte dos elementos mais antigos para liberar memória", "A complexidade é O(n) e a estratégia (adotada por linguagens como o Java 8+) consiste em converter a lista encadeada do bucket em uma árvore de busca balanceada (como a Rubro-Negra) quando o número de colisões ali supera um determinado limite, reduzindo o pior caso de busca para O(log n)", "A complexidade é O(n log n) e a estratégia envolve ordenar a lista encadeada interna usando o algoritmo QuickSort a cada inserção realizada"},
        3 // d
    }
};

#endif