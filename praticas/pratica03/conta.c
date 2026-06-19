#include <stdio.h>
#include "conta.h"

Conta conta_criar(int numero)
{
    Conta conta;
    conta.numero = numero;
    conta.saldo = 0.0;
    return conta;
}

void conta_depositar(Conta *conta, double valor)
{
    conta->saldo += valor;
}

void conta_sacar(Conta *conta, double valor)
{
    if (conta->saldo >= valor)
    {
    conta->saldo -= valor;
    }
}

double conta_ver_saldo(Conta *conta)
{
    return conta->saldo;
}