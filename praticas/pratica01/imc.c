
#include <stdio.h>

float imc(float peso, float altura)
{
    return peso / (altura*altura);
}

typedef struct {
    float peso;
    float altura;
} Pessoa;

int main() {  
    FILE *arquivo = fopen("imc.txt", "w+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    Pessoa p;
    printf("Digite o peso: ");
    scanf("%f", &p.peso);
    printf("Digite a altura: ");
    scanf("%f", &p.altura);
    float imc_result = imc(p.peso, p.altura);
    fprintf(arquivo, "Peso: %.2f\n", p.peso);
    fprintf(arquivo, "Altura: %.2f\n", p.altura);
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
