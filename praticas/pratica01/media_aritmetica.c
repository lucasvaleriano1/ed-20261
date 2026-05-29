#include <stdio.h>

float media_result(int elementos, float soma)
{
    return soma / elementos;
}

int main() { 
    FILE *arquivo = fopen("media.txt", "w+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    int elementos;
    float valores, soma = 0.0;
    printf("\nDigite a quantidade de elementos: ");
    fscanf(stdin, "%d", &elementos);
    if (elementos <= 0) {
        printf("A quantidade de elementos deve ser maior que zero.\n");
        fclose(arquivo);
        return 1;
    }
    
    for (int i = 1; i <= elementos; i++) {
        printf("\nDigite o valor do elemento %d: ", 1+i);
        fscanf(stdin, "%f", &valores);
        soma += valores;
    }
    fprintf(arquivo, "A média é: %.2f\n", media_result(elementos, soma));

    fclose(arquivo);
    return 0;
}