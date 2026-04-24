#ifndef CONTA_H
#define CONTA_H

typedef struct conta_t {
    int numero;
    double saldo;
} Conta;

Conta conta_criar(int numero);
void conta_depositar(Conta *conta, double valor);
void conta_sacar(Conta *conta, double valor);
double conta_ver_saldo(Conta *conta);
void conta_destruir(Conta *conta);

#endif // CONTA_H