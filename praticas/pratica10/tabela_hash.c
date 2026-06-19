#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

// Função Hash
int hash_funcao(int chave) {
    return chave % MAX;
    }

// Inicializa todas as posições do vetor fixo como NULL
void hash_inicializar(Hash *hash) {
    for (int i = 0; i < MAX; i++) {
        hash->tabela[i] = NULL;
    }
}

// Função Inserir
void hash_inserir(Hash *hash, int chave, int valor) {
    int index = hash_funcao(chave); // Usa diretamente a função hash baseada em MAX
    
    No *novo_no = malloc(sizeof(No));
    novo_no->chave = chave;
    novo_no->valor = valor;
    
    // Insere no início da lista encadeada daquele índice
    novo_no->prox = hash->tabela[index];
    hash->tabela[index] = novo_no;
}

// Função Buscar (Retorna o valor ou -1 se não encontrar)
int hash_buscar(Hash *hash, int chave) {
    int index = hash_funcao(chave);
    No *atual = hash->tabela[index];

    while (atual != NULL) {
        if (atual->chave == chave) {
            return atual->valor; // Encontrado
        }
        atual = atual->prox;
    }
    return -1; // Não encontrado
}

// Função Remover
void hash_remover(Hash *hash, int chave) {
    int index = hash_funcao(chave);
    No *atual = hash->tabela[index];
    No *anterior = NULL;

    while (atual != NULL) {
        if (atual->chave == chave) {
            if (anterior == NULL) {
                hash->tabela[index] = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}

// Função Exibir
void hash_exibir(Hash *hash) {
    for (int i = 0; i < MAX; i++) {
        // Para não poluir o terminal com 200 linhas vazias, 
        // só exibe os índices que possuem elementos
        if (hash->tabela[i] != NULL) {
            No *atual = hash->tabela[i];
            printf("Índice %d: ", i);
            while (atual != NULL) {
                printf("[%d: %d] -> ", atual->chave, atual->valor);
                atual = atual->prox;
            }
            printf("NULL\n");
        }
    }
}

// Função Destruir (Libera apenas os nós alocados dinamicamente)
void hash_destruir(Hash *hash) {
    for (int i = 0; i < MAX; i++) {
        No *atual = hash->tabela[i];
        while (atual != NULL) {
            No *temp = atual;
            atual = atual->prox;
            free(temp);
        }
        hash->tabela[i] = NULL;
    }
}