/*Escriba un programa que pida al usuario un número, y muestre el mensaje "has
introducido el numero ---" (mostrando el número que ha sido introducido). Esta acción
debe repetirse hasta que el usuario introduzca el número 0. En ese momento se
mostrará el mensaje "Finalizando: Se ha introducido el número 0". Además, se debe
mostrar cuántos números se han introducido y su suma.*/

#include <stdio.h>

int main(){
	int num, cantidad, suma;
	
	suma=0;
 	cantidad=0;
 	
 	printf("Introduzca un numero: ");
 	scanf("%d",&num);
 	
	while(num != 0){
		
	printf("\nHas introducido el numero %d: ",num);
	
	cantidad=cantidad+1;
	suma=suma+num;
	
	printf("\nIntroduzca un numero: ");
 	scanf("%d",&num);	
	}
		
 	printf ("Finalizando: Se ha introducido el numero 0\n");
 	printf ("La cantidad de numeros introducidos es %d\n", cantidad);
 	printf ("La suma de los numeros introducidos es %d\n", suma);
 	
	return 0;
	
}