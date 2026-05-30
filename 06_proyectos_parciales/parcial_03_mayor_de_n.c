//Obtener el mayor de 10 números. Usando ciclo for con cualquiera estructura de control de seleccion (simple, doble, multiple)


#include <stdio.h>


  int main(){
	int i=1;
	int numero, mayor;
	
	
	printf("Introduzca un numero %d: ", i);
	scanf("%d", &numero);
	
	mayor= numero;
	
	for(i = 2; i <= 10; i++ ){
		printf("Introduzca un numero %d: ", i);
		scanf("%d", &numero);	
		
		if (numero > mayor)
 		mayor = numero;		
 		
 }	
 	printf("El numero mayor es: %d \n", mayor);
  	
  	return 0;
  	
	}
