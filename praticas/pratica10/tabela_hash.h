#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#define MAX 200

typedef struct No {
    int chave;
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *tabela[MAX];
} Hash;
int hash_funcao(int chave);
void hash_inicializar(Hash *hash);
void hash_inserir(Hash *hash, int chave, int valor);
int hash_buscar(Hash *hash, int chave);
void hash_remover(Hash *hash,int chave);
void hash_exibir(Hash *hash);
void hash_destruir(Hash *hash);

#endif