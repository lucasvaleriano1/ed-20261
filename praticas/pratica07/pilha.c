#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* pilha_criar() { // Função para criar uma nova pilha
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    pilha->quantidade = 0;
    return pilha;
}


int pilha_esta_vazia(Pilha *pilha) { // Função para verificar se a pilha está vazia
    return (pilha == NULL) || (pilha->quantidade == 0);
}


No *pilha_topo(Pilha *pilha) { // Função para obter o elemento no topo da pilha
    if (pilha_esta_vazia(pilha)) return NULL;
    return pilha->topo;
}


void pilha_empilhar(Pilha *pilha, int valor) { // Função que adiciona um elemento no topo da pilha
    No *novo_no = (No *)malloc(sizeof(No));

    if (novo_no == NULL) return; // Verificar se a alocação de memória foi bem-sucedida
    // Inicializar o novo nó com o valor e ajustar os ponteiros
    novo_no->dado = valor;
    novo_no->proximo = pilha->topo;
    pilha->topo = novo_no;
    pilha->quantidade++;
}


void pilha_desempilhar(Pilha *pilha) { // Função que retira um elemento no topo da pilha
    if (pilha_esta_vazia(pilha)) return;
    // Armazenar o nó a ser removido, atualizar o topo da pilha e liberar a memória do nó removido
    No *temp = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(temp); // Liberar a memória do nó removido
    pilha->quantidade--;
}


void pilha_destruir(Pilha *pilha) { // Função para destruir a pilha e liberar a memória alocada
    while (!pilha_esta_vazia(pilha)) { // Desempilhar todos os elementos da pilha antes de liberar a memória da estrutura da pilha
        pilha_desempilhar(pilha);
    }
    free(pilha); // Liberar a memória alocada para a estrutura da pilha
}

void pilha_exibir(Pilha *pilha) {
    No *atual = pilha->topo;
    printf("[");
    while (atual != NULL) {
        printf("%d", atual->dado);
        if (atual->proximo != NULL)
            printf(", ");
        atual = atual->proximo; /* Evita segmentation fault:
        Acessando o próximo nó quando atual for NULL.*/
    }
    printf("]\n");
}