#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

arvore* criarBST() {
    arvore *arv = (arvore*)malloc(sizeof(arvore));
    if (arv != NULL) {
        arv->raiz = NULL;
    }
    return arv;
}

No* criarNo(int valor) {
    No *novoNo = (No*)malloc(sizeof(No));
    if (novoNo != NULL) {
        novoNo->dado = valor; 
        novoNo->esquerda = NULL; 
        novoNo->direita = NULL;
    }
    return novoNo;
}

void inserir(arvore *arvore, int valor) {
    No *novoNo = criarNo(valor);
    if (novoNo == NULL) return;

    if (arvore->raiz == NULL) {
        arvore->raiz = novoNo;
    } else {
        No *atual = arvore->raiz;
        No *pai = NULL;
        while (atual != NULL) {
            pai = atual;
            if (valor < atual->dado) {
                atual = atual->esquerda;
            } else {
                atual = atual->direita;
            }
        }

        if (valor < pai->dado) {
            pai->esquerda = novoNo;
        } else {
            pai->direita = novoNo;
        }
    }
}

void remover(arvore *arvore, int valor) {
    No *atual = arvore->raiz;
    No *pai = NULL;

    while (atual != NULL && atual->dado != valor) {
        pai = atual;
        if (valor < atual->dado) {
            atual = atual->esquerda;
        } else {
            atual = atual->direita;
        }
    }

    if (atual == NULL) {
        printf("Valor %d não encontrado na árvore.\n", valor);
        return; 
    }

    if (atual->esquerda == NULL && atual->direita == NULL) {
        if (pai == NULL) {
            arvore->raiz = NULL;
        } else if (pai->esquerda == atual) {
            pai->esquerda = NULL;
        } else {
            pai->direita = NULL;
        }
        free(atual);
    }
    
    else if (atual->esquerda == NULL || atual->direita == NULL) {
        No *filho = (atual->esquerda != NULL) ? atual->esquerda : atual->direita;

        if (pai == NULL) {
            arvore->raiz = filho;
        } else if (pai->esquerda == atual) {
            pai->esquerda = filho;
        } else {
            pai->direita = filho;
        }
        free(atual);
    }
    else {
        No *paiSucessor = atual;
        No *sucessor = atual->direita;

        while (sucessor->esquerda != NULL) {
            paiSucessor = sucessor;
            sucessor = sucessor->esquerda;
        }

        atual->dado = sucessor->dado;

        if (paiSucessor->esquerda == sucessor) {
            paiSucessor->esquerda = sucessor->direita;
        } else {
            paiSucessor->direita = sucessor->direita;
        }
        free(sucessor);
    }
}

void exibirPreOrdem(No *no) {
    if (no != NULL) {
        printf("%d ", no->dado); 
        exibirPreOrdem(no->esquerda); 
        exibirPreOrdem(no->direita); 
    }
}

void exibirEmOrdem(No *no) {
    if (no != NULL) {
        exibirEmOrdem(no->esquerda); 
        printf("%d ", no->dado); 
        exibirEmOrdem(no->direita); 
    }
}

void exibirPosOrdem(No *no) {
    if (no != NULL) {
        exibirPosOrdem(no->esquerda); 
        exibirPosOrdem(no->direita); 
        printf("%d ", no->dado); 
    }
}

int arvore_esta_vazia(arvore *arvore) {
    return (arvore->raiz == NULL); 
}

void destruir_arvore(No *no) {
    if (no != NULL) {
        destruir_arvore(no->esquerda); 
        destruir_arvore(no->direita); 
        free(no); 
    }
}