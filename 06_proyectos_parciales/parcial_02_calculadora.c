//Calculadora que suma, resta, multiplica y divide usando un ciclo do while. Se puede usar cualquier estructura de control de seleccion.


#include <stdio.h>

int main() {
    char operacion;
    float num1, num2, resultado;

    do {
        printf("\nIngrese la operacion (+, -, *, /) o 's' para salir: ");
        scanf(" %c", &operacion);

        if (operacion == 's' || operacion == 'S') 
            break;

        printf("Ingrese el primer numero: ");
        scanf("%f", &num1);
        printf("Ingrese el segundo numero: ");
        scanf("%f", &num2);

        int operacion_valida = 1; 

        switch (operacion) {
            case '+': resultado = num1 + num2; break;
            case '-': resultado = num1 - num2; break;
            case '*': resultado = num1 * num2; break;
            case '/':
                if (num2 == 0) {
                    printf("Error: No se puede dividir por cero.\n");
                    operacion_valida = 0; 
                } else {
                    resultado = num1 / num2;
                }
                break;
            default:
                printf("Operacion invalida.\n");
                operacion_valida = 0;
        }

        if (operacion_valida) {
            printf("Resultado: %.2f\n", resultado);
        }

    } while (1); 

    return 0;
}
