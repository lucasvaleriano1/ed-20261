#include <stdio.h>

int matriz1(FILE *arquivo) { // Por ter um laço, essa opção é mais rápida do que a matriz2 (Tempo de execução: 0,000016 segundos)
    int matriz[10][10];
    for (int k = 0; k < 100; k++) { 
        int i = k / 10;
        int j = k % 10;
        matriz[i][j] = i * 10 + j;
        fprintf(arquivo, "%d ", matriz[i][j]);
        if(j == 9) {
            fprintf(arquivo, "\n");
        }
    }
    return 0;
}

int matriz2(FILE *arquivo) { // Por ter dois laços aninhados, essa opção é mais lenta do que a matriz1 (Tempo de execução: 0,000028 segundos)
    int matriz[10][10];
    for (int i = 0; i < 10; i++) { 
        for (int j = 0; j < 10; j++) {
            matriz[i][j] = i * 10 + j;
            fprintf(arquivo, "%d ", matriz[i][j]);
        }
        fprintf(arquivo, "\n");
    }
    return 0;
}

int main() {
    FILE *arquivo = fopen("exibe_matriz.txt", "w+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    int opcao;
    printf("Qual matriz deseja exibir?\n");
    printf("1 - Matriz com um laço\n");
    printf("2 - Matriz com dois laços aninhados\n");
    if (scanf("%d", &opcao) != 1) {
        printf("Entrada inválida.\n");
        return 1;
    }
    if (opcao == 1) {
        matriz1(arquivo);
    } else if (opcao == 2) {
        matriz2(arquivo);
    } else {
        printf("Opção inválida.\n");
    }
    fclose(arquivo);

    return 0;
}