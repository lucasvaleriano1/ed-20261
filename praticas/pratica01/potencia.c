#include <stdio.h>

float pot(float num, int potencia) {
    float valor = 1.0;
    if (potencia == 0) { // potência zero
        valor = 1.0;
    } else if (potencia > 0) { // potência positiva
        for (int i = 0; i < potencia; i++) {
            valor *= num;
        }
    } else { // potência negativa
        for (int i = 0; i < -potencia; i++) {
            valor *= num;
        }
        valor = 1 / valor;
    }
    return valor;
}

int main() { 
    FILE *arquivo = fopen("potencia.txt", "w+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    int potencia;
    float num;
    printf("\nDigite a potencia a ser elevada: ");
    fscanf(stdin, "%d", &potencia);
    printf("\nDigite um número: ");    
    
    // Verificar se a entrada é válida
    if (fscanf(stdin, "%f", &num) != 1) {
        printf("Entrada inválida.\n");
        fclose(arquivo);
        return 1;
    }

    // Arquivo de texto para salvar o resultado da potência
    fprintf(arquivo, "O resultado da potência é: %.2f\n", pot(num, potencia));
    fclose(arquivo);
    
    return 0;
}