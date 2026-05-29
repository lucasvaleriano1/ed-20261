#include <stdio.h>

float imc(float peso, float altura)
{
    if (peso <= 0 || altura <= 0) {
        fprintf(stderr, "Erro: Peso e altura devem ser valores positivos.\n");
        return -1;
    }
    return peso / (altura*altura);
}

int main() {  
    FILE *arquivo = fopen("imc.txt", "w+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    float imc_result = imc(70, 1.75);
    fprintf(arquivo, "IMC: %.2f\n", imc_result);
    if (imc_result < 18.5) {
        fprintf(arquivo, "Abaixo do peso.\n");
    } else if (imc_result < 25) {
        fprintf(arquivo, "Peso normal.\n");
    } else if (imc_result < 30) {
        fprintf(arquivo, "Sobrepeso.\n");
    } else {
        fprintf(arquivo, "Obesidade.\n");
    }
    fclose(arquivo);

    return 0;
}