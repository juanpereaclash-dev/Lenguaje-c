#include <stdio.h>

int main() {
    int opcion;
    int opcionValida = 0; 

    do {
        
        printf("\nMenu:\n");
        printf("1. Opcion 1\n");
        printf("2. Opcion 2\n");
        printf("3. Opcion 3\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        // Verificar si la opción es válida
        if (opcion >= 1 && opcion <= 3) {
            opcionValida = 1; // La opción es válida
        } else {
            printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcionValida == 0); 

    
    printf("Usted selecciono la opcion %d.\n", opcion);

    return 0;
}
