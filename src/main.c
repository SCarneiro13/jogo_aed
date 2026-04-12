#include <stdio.h>
#include "criarJogadores.h"
#include "queue.h"
#include "user.h"

int main(){
    tp_fila fila;
    inicializaFila(&fila);

    criarJogadores(&fila);

    return 0;
}
