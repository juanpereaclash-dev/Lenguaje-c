/*Escriba un programa en C que pida dos números enteros al usuario, y determine cuál es
mayor, el primero o el segundo. Modifíquelo para considerar también la posibilidad de
que sean iguales.*/

#include <stdio.h>

int main(){
	int num1, num2;
	
	printf("Introduzca un numero: ");
	scanf("%d", &num1);
	
	printf("Introduzca un segundo numero: ");
	scanf("%d", &num2);
	
	if(num1 > num2)
		printf("El primer numero es mayor que el segundo ");
	else if(num2 > num1)
		printf("El segundo numero es mayor que el primero ");
	else
		printf("Tienen el mismo valor");		
}