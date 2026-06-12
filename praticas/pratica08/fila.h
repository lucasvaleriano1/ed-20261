#ifndef FILA_H
#define FILA_H

typedef struct No {
    int dado;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int quantidade;
} Fila;

Fila* fila_criar();
void fila_enfileirar(Fila *fila, int valor);
void fila_desenfileirar(Fila *fila);
int fila_inicio(Fila *fila);
void fila_exibir(Fila *fila);
int  fila_esta_vazia(Fila *fila);
void fila_destruir(Fila *fila);


#endif