#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void) {
    Pilha *pilha = pilha_criar();

    pilha_empilhar(pilha, 10);
    pilha_empilhar(pilha, 20);
    pilha_empilhar(pilha, 30);

    pilha_exibir(pilha);

    pilha_desempilhar(pilha);
    pilha_desempilhar(pilha);
    pilha_exibir(pilha);
    printf("Topo da pilha após desempilhar: %d\n", pilha_topo(pilha)->dado);

    pilha_destruir(pilha);

    return 0;
}

// Copilar: gcc main.c pilha.c -o main
// Executar: ./main