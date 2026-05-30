/*Escriba un programa en C que solicite 10 números enteros positivos al usuario y
calcule y muestre los siguientes valores:
• La suma de todos los números leídos.
• La media de los números.
• El mayor número introducido.
• El menor número introducido.*/

#include <stdio.h>
#include <math.h>

int main(){
	int i=1;
	int numero, mayor, menor, suma;
	float media;
	
	printf("Introduzca un numero %d: ", i);
	scanf("%d", &numero);
	
	mayor= numero;
	menor= numero;
	suma= numero;
	
	for(i = 2; i <= 10; i++ ){
		printf("Introduzca un numero %d: ", i);
		scanf("%d", &numero);	
		
		suma=suma+numero;
		if (numero > mayor)
 		mayor = numero;
 		
 		if (numero < menor)
 		menor = numero;
 }
 	media=suma/10.0;
 	
 	printf("La suma de todos los numeros es: %d \n", suma);
 	printf("Su media es: %f \n", media);
 	printf("El numero mayor es: %d \n", mayor);
 	printf("El numero menor es: %d \n", menor);
 	
 	return 0,
	 	
	}
	
	
	
	
	
