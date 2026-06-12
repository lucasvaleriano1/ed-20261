#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

lista_t *lista_criar()
{
    lista_t *lista = (lista_t *)malloc(sizeof(lista_t));

    if (lista != NULL) // Cria lista vazia
    {
        lista->primeiro = NULL;
        lista->ultimo = NULL;
        lista->quantidade = 0;
    }

    return lista;
}


void lista_inserir(lista_t *lista, int valor) // Ultima posição
{
    no_t *novo = (no_t *)malloc(sizeof(no_t)); // Aloca memória para um novo nó

    if (novo == NULL) return; // Verifica se a alocação foi bem-sucedida

    // Valor do novo nó e ponteiro NULL para o próximo nó
    novo->dado = valor;
    novo->proximo = NULL;

    if (lista_esta_vazia(lista)) // Se a lista estiver vazia, o novo nó é o primeiro
    {
        lista->primeiro = novo;
    }
    else
    {
        lista->ultimo->proximo = novo;
    }

    // O novo nó é o último da lista
    lista->ultimo = novo;
    lista->quantidade++;
}


void lista_remover(lista_t *lista, int valor)
{
    if (lista_esta_vazia(lista)) return;

    no_t *no_atual = lista->primeiro;
    no_t *no_anterior = NULL;

    while (no_atual != NULL)
    {
        if (no_atual->dado == valor) // Encontrou o nó a ser removido
        {
            if (no_anterior == NULL) // O nó a ser removido é o primeiro
            {
                lista->primeiro = no_atual->proximo;
            }
            else
            {
                no_anterior->proximo = no_atual->proximo;
            }

            if (no_atual == lista->ultimo) // O nó a ser removido é o último
            {
                lista->ultimo = no_anterior;
            }

            free(no_atual); // Libera a memória do nó removido
            lista->quantidade--;
            return; // Sai da função após remover o nó
        }

        no_anterior = no_atual;
        no_atual = no_atual->proximo;
    }
}



void lista_exibir(lista_t *lista)
{
    if (lista_esta_vazia(lista)) {
        printf("A lista esta vazia.\n");
        return;
    }

    no_t *no = lista->primeiro;
    while (no != NULL) {
        printf("%i ", no->dado);
        no = no->proximo;
    }
    printf("\n");
}


int lista_esta_vazia(lista_t *lista)
{
    return lista != NULL && lista->primeiro == NULL;
}


no_t *lista_buscar(lista_t *lista, int valor)
{
    if (lista_esta_vazia(lista)) return NULL;

    // Inicia a busca a partir do primeiro nó da lista, até chegar ao final (quando o ultimo elemento é NULL)
    no_t *no = lista->primeiro;
    while (no != NULL)
    {
        if (no->dado == valor) // Se o valor do nó atual for igual ao valor buscado, retorna o nó
            return no;
        no = no->proximo;
    }

    // Pior caso: o valor não foi encontrado na lista, retorna NULL
    return NULL;
}


void lista_destruir(lista_t *lista)
{
    free(lista); // Libera a memória alocada para a estrutura da lista
}