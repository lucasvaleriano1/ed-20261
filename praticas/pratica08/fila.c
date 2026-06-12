#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* fila_criar() {
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    if (fila != NULL) {
        fila->inicio = NULL;
        fila->fim = NULL;
        fila->quantidade = 0;
    }
    return fila;
}

void fila_enfileirar(Fila *fila, int valor) {
    if (fila != NULL) {
        No *novo_no = (No *)malloc(sizeof(No));
        if (novo_no != NULL) {
            novo_no->dado = valor;
            novo_no->proximo = NULL;

            if (fila->fim == NULL) { // Fila vazia
                fila->inicio = novo_no;
            } else {
                fila->fim->proximo = novo_no; // Aponta o próximo do último nó para o novo nó
            }
            fila->fim = novo_no;  // Adcionar no fim da fila
            fila->quantidade++;
        }
    }
}

void fila_desenfileirar(Fila *fila) {
    if (fila != NULL && fila->inicio != NULL) {
        No *temp = fila->inicio;
        fila->inicio = fila->inicio->proximo; // Move o início para o próximo nó
        free(temp); // Libera a memória do nó removido
        fila->quantidade--;

        if (fila->inicio == NULL) { // Se a fila ficou vazia, atualiza o fim para NULL
            fila->fim = NULL;
        }
    } else {
        printf("Fila vazia. Não é possível desenfileirar.\n");
    }
}

void fila_exibir(Fila *fila) {
    if (fila != NULL) {
        No *atual = fila->inicio;
        printf("Fila: ");
        while (atual != NULL) {
            printf("%d ", atual->dado);
            atual = atual->proximo;
        }
        printf("\n");
    }
}

int fila_inicio(Fila *fila) {
    if (fila != NULL && fila->inicio != NULL) {
        return fila->inicio->dado;
    }
    printf("Fila vazia. Não há início para retornar.\n");
    return -1; // Retorna -1 para indicar que a fila está vazia
}

int fila_esta_vazia(Fila *fila) {
    return (fila != NULL && fila->quantidade == 0);
}

void fila_destruir(Fila *fila) {
    if (fila != NULL) {
        No *atual = fila->inicio;
        while (atual != NULL) {
            No *temp = atual;
            atual = atual->proximo;
            free(temp); // Libera a memória de cada nó
        }
        free(fila); // Libera a memória da estrutura da fila
    }
}