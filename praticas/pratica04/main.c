#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

#define TAMANHO 10000

int main() {
    clock_t tempo_inicial, tempo_final;
    double dur_bubble, dur_selection, dur_quick;

    int vetor [TAMANHO];
    for (int i = 0; i < TAMANHO; i++) 
    {
        vetor [i] = rand();
    }

    // Bubble Sort
    tempo_inicial = clock();
    bubble_sort (vetor , TAMANHO);Expand commentComment on line R20
    tempo_final = clock();
    // Tempo de execução do Bubble Sort
    dur_bubble = (double)(tempo_final - tempo_inicial) / CLOCKS_PER_SEC;
    

    // Selection Sort
    tempo_inicial = clock();
    selection_sort(vetor, 0, TAMANHO - 1);
    tempo_final = clock();
    // Tempo de execução do Selection Sort
    dur_selection = (double)(tempo_final - tempo_inicial) / CLOCKS_PER_SEC;

    // Quick Sort
    tempo_inicial = clock();
    quick_sort(vetor, 0, TAMANHO - 1);
    tempo_final = clock();
    // Tempo de execução do Quick Sort
    dur_quick = (double)(tempo_final - tempo_inicial) / CLOCKS_PER_SEC;

    // Imprime o vetor ordenado
    imprimir_vetor (vetor, TAMANHO);

    // Imprime os tempos de execução dos algoritmos
    printf("Tempo de execução do Bubble Sort: %f segundos\n", dur_bubble); // 10mil elementos, o tempo foi 0.423219 segundos
    printf("Tempo de execução do Selection Sort: %f segundos\n", dur_selection); // 10mil elementos, o tempo foi 0.172459 segundos
    printf("Tempo de execução do Quick Sort: %f segundos\n", dur_quick); // 10mil elementos, o tempo foi 0.482881 segundos

    return 0;
}
