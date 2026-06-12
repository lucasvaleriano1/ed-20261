#include <stdio.h>
#include "lista_linear.h"

int main() {
    lista_t *lista = lista_criar();

    lista_inserir(lista, 50);
    lista_inserir(lista, 25);
    lista_inserir(lista, 10);
    lista_inserir(lista, 60);
    lista_inserir(lista, 5);
    lista_inserir(lista, 41);
    lista_inserir(lista, 9);

    printf("A lista em %i nos => ", lista->quantidade);
    no_t *no = lista->primeiro;
    while (no != NULL) {
        printf("%i ", no->dado);
        no = no->proximo;
    }
    printf("\n");

    no = lista_buscar(lista, 60);
    printf("O valor 60 esta no No %p\n", no);
    no = lista_buscar(lista, 65);
    printf("O valor 65 esta no No %p\n", no);


    lista_remover(lista, 50);
    lista_remover(lista, 10);
    lista_remover(lista, 9);

    printf("A lista em %i nos => ", lista->quantidade);
    no = lista->primeiro;
    while (no != NULL) {
        printf("%i ", no->dado);
        no = no->proximo;
    }
    printf("\n");

    return 0;
}

// Copilar: gcc main.c lista_linear.c -o main
// Executar: ./main