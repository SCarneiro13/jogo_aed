#ifndef USUARIO_H
#define USUARIO_H

typedef struct{
    int dificil;
    int medio;
    int facil;
} Acertos;

typedef struct{
    char nick[30];
    int casaAtual;
    Acertos acertos;
    int erros;
} Jogador;

#endif