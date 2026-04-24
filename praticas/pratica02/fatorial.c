#include <stdio.h>

int fatorecur(FILE *arquivo, int num) {
    if (num == 0 || num == 1) { // fatorial de zero
        return 1;
    } else {
        return num * fatorecur(arquivo, num - 1);
    }
}

int fato(FILE *arquivo, int num) {
    int resultado = 1;
    for (int i = 2; i <= num; i++) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    FILE *arquivo = fopen("fatorial.txt", "w+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    int num;
    printf("Digite um número inteiro positivo: ");
    if (scanf("%d", &num) != 1) {
        fprintf(arquivo, "Entrada inválida.\n");
        fclose(arquivo);
        return 1;
    }
    if (num < 0) {
        fprintf(arquivo, "Entrada inválida. Digite um número inteiro positivo.\n");
        fclose(arquivo);
        return 1;
    }
    printf("Deseja calcular o fatorial de %d por recursividade? (s/n): ", num);
    char resposta;
    scanf(" %c", &resposta);
    if (resposta == 's' || resposta == 'S') {
        fprintf(arquivo, "O fatorial de %d é %d\n", num, fatorecur(arquivo, num));
    } else {
        fprintf(arquivo, "O fatorial de %d é %d\n", num, fato(arquivo, num));
    }
    fclose(arquivo);

    return 0;
}