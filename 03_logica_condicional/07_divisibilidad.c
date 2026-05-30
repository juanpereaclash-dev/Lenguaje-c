/*Escriba un programa en C que pida dos números enteros al usuario, y determine si el
primero es divisible entre el segundo.*/

#include <stdio.h>

int main(){
	
	int num1, num2;
	
	printf("Introduzca el valor del primer numero: ");
	scanf("%d", &num1);
	
	printf("Introduzca el valor del segundo numero: ");
	scanf("%d", &num2);
	
	if(num1 % num2 == 0)
		printf("Son divisibles");
	else
		printf("No son divisibles");
		
	return 0;		
	
	
}