//Realizar el factorial de un número entero positivo. Usando el ciclo for con una estructura de control de seleccion doble.

#include <stdio.h>


int main() {
    int numero, factorial = 1;

    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &numero);

    
    if (numero < 0) {
        printf("El numero debe ser positivo.\n");
    } else {
        
        for ( int i = 1; i <= numero; i++) {
            factorial *= i;
        }

        printf("El factorial de %d es: %d\n", numero, factorial);
    }

    return 0;
}
