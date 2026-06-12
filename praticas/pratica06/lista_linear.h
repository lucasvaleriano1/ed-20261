#ifndef LISTA_LINEAR_H
#define LISTA_LINEAR_H

typedef struct no_t {
    int dado;
    struct no_t *anterior;
    struct no_t *proximo;
} no_t;

typedef struct {
    no_t *primeiro;
    no_t *ultimo;
    int quantidade;
} lista_t;

lista_t *lista_criar();
void lista_inserir(lista_t *lista, int valor);
void lista_remover(lista_t *lista, int valor);
void lista_exibir(lista_t *lista);
int lista_esta_vazia(lista_t *lista);
no_t *lista_buscar(lista_t *lista, int valor);
void lista_destruir(lista_t *lista);

#endif