#include "mathPhysToolkit.h"

int main() {
    setlocale(LC_ALL, "");
    char expression[100];
    float result;

    printf("Digite a express�o matem�tica (use espa�os entre os elementos, ex: 2 + 3 * 4): ");
    fgets(expression, sizeof(expression), stdin);

    result = calculadora(expression);

    if (isnan(result)) {
        printf("Erro: Divis�o por zero detectada.\n");
    } else {
        printf("O resultado da express�o �: %.2f\n", result);
    }

    return 0;
}
