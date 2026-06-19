#include <stdio.h>
#include "arvore_binaria.h"

int main() {
    struct BST *arvore = criarBST();

    inserir(arvore, 10);
    inserir(arvore, 5);
    inserir(arvore, 120);
    inserir(arvore, 1);
    inserir(arvore, 49);

    remover(arvore, 5);
    remover(arvore, 10);
    remover(arvore, 11); // Teste de remoção de um valor que não existe na árvore
    
    printf("Árvore em pré-ordem: ");
    exibirPreOrdem(arvore->raiz);

    printf("\nÁrvore em ordem: ");
    exibirEmOrdem(arvore->raiz);

    printf("\nÁrvore em pós-ordem: ");
    exibirPosOrdem(arvore->raiz);

    return 0;
}