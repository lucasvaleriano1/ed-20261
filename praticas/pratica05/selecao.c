#include <stdio.h>
#include "selecao.h"


int linear_search(int v[], int n, int target) {
    for (size_t i = 0; i < n; i++) {
        if (v[i] == target) {
            return (int)i; // Retorna o índice do elemento encontrado
        }
    }
    return -1; // Retorna -1 se o elemento não for encontrado
}

int quick_select(int v[], int n, int k) {
    if (k < 1 || k > n) {
        return -1; // Retorna -1 se k for inválido
    }

    int pivot = v[n / 2]; // Escolhe o pivô como o elemento do meio
    size_t left = 0, right = n - 1;

    while (left <= right) {
        while (v[left] < pivot) {
            left++;
        }
        while (v[right] > pivot) {
            right--;
        }
        if (left <= right) {
            // Troca os elementos
            int temp = v[left];
            v[left] = v[right];
            v[right] = temp;
            left++;
            right--;Expand commentComment on line R36
        }
    }
    if (k - 1 < left) {
        return quick_select(v, left, k); // Busca na parte esquerdaExpand commentComment on lines R39 to R40
    } else if (k - 1 > left) {
        return quick_select(v + left, n - left, k - left); // Busca na parte direita
    } else {
        return v[left]; // Retorna o k-ésimo menor elemento
    }
}

int busca_sequencial(int v[], int n, int valor) {
    for (int i = 0; i < n; i++) { // O(n)
        if (v[i] == valor) {
            return i; // Retorna o índice onde o valor foi encontrado
        }
    }
    return -1; // Retorna -1 se o valor não for encontrado
}
