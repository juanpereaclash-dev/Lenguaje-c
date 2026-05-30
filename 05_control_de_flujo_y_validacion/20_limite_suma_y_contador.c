/*Escriba un programa en C que solicite números al usuario hasta que se hayan
introducido 10 números o la suma de todos los números leídos sea mayor que 100. A
continuación mostrar un mensaje indicando qué condición se ha cumplido (es decir, si
se han introducido 10 números o si su suma es mayor que 100).*/

#include <stdio.h>

int main(){
	int num, suma, contador;
	
	suma=0;
	contador=0;
	
	do{
		printf("Introduzca un numero: ");
		scanf("%d", &num);
		
		suma=suma+num;
		contador=contador+1;
					
	} while ((contador<10)&&(suma<=100));
	
	if	(contador==10)
 	printf ("Se han introducido 10 numeros\n");
 	if (suma>100)
 	printf ("La suma de los numeros introducidos es superior a 100\n");
 
	
	return 0;
	 	
	}