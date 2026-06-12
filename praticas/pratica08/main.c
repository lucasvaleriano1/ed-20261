#include <stdio.h>
#include "fila.h"

int main(void) {
    Fila *fila = fila_criar();
    if (fila == NULL) {
        printf("Erro ao criar a fila.\n");
        return 1;
    }

    fila_enfileirar(fila, 10);
    fila_enfileirar(fila, 20);
    fila_enfileirar(fila, 30);
    fila_enfileirar(fila, 40);
    fila_enfileirar(fila, 50);

    printf("Elemento no início da fila: %d\n", fila_inicio(fila));
    printf("Fila após enfileirar elementos:\n");
    fila_exibir(fila);

    fila_desenfileirar(fila);
    fila_desenfileirar(fila);
    printf("Fila após desenfileirar elemento:\n");
    fila_exibir(fila);

    fila_destruir(fila);

    return 0;
}

// Copilar: gcc -o main main.c fila.c
// Executar: ./main