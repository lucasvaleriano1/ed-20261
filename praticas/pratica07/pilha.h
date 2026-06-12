#ifndef PILHA_H
#define PILHA_H

typedef struct No {
    int dado;
    struct No *proximo;
} No;

typedef struct {
    No *topo;
    int quantidade;
} Pilha;

Pilha* pilha_criar();
int pilha_esta_vazia(Pilha *pilha);
No *pilha_topo(Pilha *pilha);
void pilha_empilhar(Pilha *pilha, int valor);
void pilha_desempilhar(Pilha *pilha);
void pilha_destruir(Pilha *pilha);
void pilha_exibir(Pilha *pilha);

#endif