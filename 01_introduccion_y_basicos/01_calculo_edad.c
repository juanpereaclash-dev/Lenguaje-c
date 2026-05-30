/*Escriba un programa que muestre en la pantalla un mensaje de saludo, por ejemplo
"Hola",y luego muestre el mensaje "Por favor introduzca el año en que nació". El
programa debe leer ese valor y almacenarlo en una variable de tipo entero llamada
fecha. Por último haga que el programa escriba la frase " Si usted nació en <valor de la
fecha leída> este año cumple <edad calculada> años.
Es recomendable que vaya escribiendo el programa por pasos (mostrar saludo, pedir
fecha, leer fecha,…) y compilándolo después de cada paso para comprobar que
funciona.*/

#include <stdio.h>

int main() {

    int fecha;
    int edad;

    printf("Hola\n");
    printf("Por favor introduzca el anio en que nacio:\n");
    
   
    if (scanf("%d", &fecha) != 1) {
        printf("Error: entrada no valida.\n");
        return 1;
    }


    edad = 2026 - fecha;

    printf("Si usted nacio en %d, este anio cumple: %d anios.\n", fecha, edad);

    return 0;
}