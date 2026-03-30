#include <stdio.h>

int main() {
    int saque;
    int n200, n100, n50, n20, n10, n5, n2;

    printf("Digite o valor do saque (Máximo 1000): ");
    scanf("%d", &saque);

    if (saque <= 0 || saque > 1000) {
        printf("Erro: Valor de saque inválido.\n");
        return 1;
    }

    n200 = saque / 200;
    saque %= 200;

    n100 = saque / 100;
    saque %= 100;

    n50 = saque / 50;
    saque %= 50;

    n20 = saque / 20;
    saque %= 20;

    n10 = saque / 10;
    saque %= 10;

    n5 = saque / 5;
    saque %= 5;

    n2 = saque / 2;
    saque %= 2;

    printf("\nQuantidade de notas entregues:\n");
    if (n200 > 0) printf("%d nota(s) de R$ 200\n", n200);
    if (n100 > 0) printf("%d nota(s) de R$ 100\n", n100);
    if (n50 > 0) printf("%d nota(s) de R$ 50\n", n50);
    if (n20 > 0) printf("%d nota(s) de R$ 20\n", n20);
    if (n10 > 0) printf("%d nota(s) de R$ 10\n", n10);
    if (n5 > 0) printf("%d nota(s) de R$ 5\n", n5);
    if (n2 > 0) printf("%d nota(s) de R$ 2\n", n2);

    // Caso o usuário peça um valor que não pode ser totalmente sacado (ex: R$ 3)
    if (saque > 0) {
        printf("\nAviso: Restou R$ %d que não pôde ser sacado com as notas disponíveis.\n", saque);
    }

    return 0;
}