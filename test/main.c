#include "mathPhysToolkit.h"

int main() {
    setlocale(LC_ALL, "");
    char expression[100];
    float result;

    printf("Digite a expressão matemática (use espaços entre os elementos, ex: 2 + 3 * 4): ");
    fgets(expression, sizeof(expression), stdin);

    result = calculadora(expression);

    if (isnan(result)) {
        printf("Erro: Divisão por zero detectada.\n");
    } else {
        printf("O resultado da expressão é: %.2f\n", result);
    }

    return 0;
}
