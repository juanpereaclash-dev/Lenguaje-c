/*Escriba un programa que lea un número entero y escriba un mensaje si el número es
mayor que 100*/

#include <stdio.h>

int main(){
	int n;
	
	printf("Introduzca un numero entero: ");
	scanf("%d", &n);
	
	if(n>100)
	    printf("El numero introducido es mayor a 100");
	else
		printf("El numero no es mayor a 100");    
	
	return 0;
	
	
} 