#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"

#define TAMANHO 1000

int main() {
    clock_t inicio_tempo, final_tempo;
    int vetor[TAMANHO];

    printf("[");
    for(int i =0; i< TAMANHO; i++){
        vetor[i] = rand() % TAMANHO; // Preenche o vetor com números aleatórios
        printf("%i, ", vetor[i]);
    }
    printf("]\n");

    printf("Primeiro = %i, Ultimo = %i\n", vetor[0], vetor[TAMANHO-1]);

    int valor;
    printf("Entre com um numero para buscar: ");
    scanf("%i", &valor);

    inicio_tempo = clock();
    int linear = linear_search(vetor, TAMANHO, valor);
    final_tempo = clock();
    double tem_linear_search = (double)(final_tempo - inicio_tempo) / CLOCKS_PER_SEC;

    inicio_tempo = clock();
    int quick = quick_select(vetor, TAMANHO, valor);
    final_tempo = clock();
    double tem_quick_select = (double)(final_tempo - inicio_tempo) / CLOCKS_PER_SEC;


    if(linear != -1 || quick != -1){
        printf("Valor encontrado na posicao: %i\n", linear != -1 ? linear : quick);Expand commentComment on lines R36 to R37
    }else{
        printf("Valor nao encontrado\n");
    }

    printf("Linear Search tempo gasto: %f segundos\n", tem_linear_search);
    printf("Quick Select tempo gasto: %f segundos\n", tem_quick_select);

    return 0;
}
