#ifndef USUARIO_H
#define USUARIO_H

typedef struct{
    int dificil;
    int medio;
    int facil;
} Acertos;

typedef struct{
    char nick[30]; // Nome do usuario
    int casaAtual;
    Acertos acertos;
    int erros;
} Jogador;

void cadastrarJogador(Jogador *j);
void inicializarJogador(Jogador *j);

#endif