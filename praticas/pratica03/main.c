#include <stdio.h>
#include <string.h>
#include "conta.h"

int main() {
    Conta conta1 = conta_criar(1);
    Conta conta2 = conta_criar(2);

    conta_depositar(&conta1, 100.0);
    conta_depositar(&conta2, 200.0);

    printf("Saldo da conta 1: %.2f\n", conta_ver_saldo(&conta1));
    printf("Saldo da conta 2: %.2f\n", conta_ver_saldo(&conta2));

    return 0;
}
