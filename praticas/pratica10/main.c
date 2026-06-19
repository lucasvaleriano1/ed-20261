#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

int main() {
    Hash minha_hash;

    printf("--- 1. Inicializando a Tabela Hash ---\n");
    hash_inicializar(&minha_hash);
    hash_exibir(&minha_hash);
    printf("\n");

    printf("--- 2. Inserindo Elementos ---\n");
    // Inserindo elementos normais
    hash_inserir(&minha_hash, 10, 100);
    hash_inserir(&minha_hash, 25, 250);
    hash_inserir(&minha_hash, 32, 320);

    printf("Inserindo chaves que podem colidir para testar a lista encadeada...\n");
    hash_inserir(&minha_hash, 15, 150);
    hash_inserir(&minha_hash, 215, 2150); // Deve colidir com a chave 15 no mesmo índice
    
    hash_exibir(&minha_hash);
    printf("\n");

    printf("--- 3. Testando as Buscas ---\n");
    int chaves_para_buscar[] = {10, 215, 999}; // Duas existentes e uma inexistente
    int tam_busca = sizeof(chaves_para_buscar) / sizeof(chaves_para_buscar[0]);

    for (int i = 0; i < tam_busca; i++) {
        int chave = chaves_para_buscar[i];
        int resultado = hash_buscar(&minha_hash, chave);
        
        if (resultado != -1) { // Assumindo que -1 significa "não encontrado" na sua função
            printf("Chave %d ENCONTRADA! Valor associado: %d\n", chave, resultado);
        } else {
            printf("Chave %d NAO encontrada na tabela.\n", chave);
        }
    }
    printf("\n");

    printf("--- 4. Testando a Remoção ---\n");
    // Remover um elemento que está no meio/fim de uma colisão
    printf("Removendo a chave 215...\n");
    hash_remover(&minha_hash, 215);
    hash_exibir(&minha_hash);
    printf("\n");

    // Remover um elemento que está sozinho no índice
    printf("Removendo a chave 10...\n");
    hash_remover(&minha_hash, 10);
    hash_exibir(&minha_hash);
    printf("\n");

    printf("--- 5. Liberando a Memória (Destruir) ---\n");
    hash_destruir(&minha_hash);
    printf("Tabela hash destruída com sucesso!\n");

    return 0;
}
