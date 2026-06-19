#ifndef BST_H
#define BST_H

typedef struct No {
    int dado;
    struct No *esquerda;
    struct No *direita;
} No;

typedef struct BST {
    No *raiz;
} arvore;

arvore* criarBST();No* criarNo(int valor);
void inserir(arvore *arv, int valor);
void remover(arvore *arv, int valor);
void exibirPreOrdem(No *no);
void exibirEmOrdem(No *no);
void exibirPosOrdem(No *no);
int arvore_esta_vazia(arvore *arv); 
void destruir_arvore(No *no);

#endif