#include "mathPhysToolkit.h"

float calculadora(char *text){
    char expression[] = text;
    char *token;
    float number;
    float result = 0;
    float temp_result = 0;
    char current_operator = '+';
    char last_operator = '+';

    token = strtok(expression, " ");

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            number = atof(token);

            if (current_operator == '*' || current_operator == '/') {
                if (current_operator == '*') {
                    temp_result *= number;
                } else if (current_operator == '/') {
                    if (number != 0) {
                        temp_result /= number;
                    } else {
                        return NAN;
                    }
                }
            } else {
                if (last_operator == '+') {
                    result += temp_result;
                } else if (last_operator == '-') {
                    result -= temp_result;
                }

                temp_result = number;
                last_operator = current_operator;
            }
        } else {
            current_operator = token[0];
        }

        token = strtok(NULL, " ");
    }
    if (last_operator == '+') {
        result += temp_result;
    } else if (last_operator == '-') {
        result -= temp_result;
    }

    return result;
}
