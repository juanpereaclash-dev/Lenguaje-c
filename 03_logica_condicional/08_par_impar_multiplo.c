//Escriba un programa en C que pida un número al usuario e indique si es par o impar.
//En caso de que sea par indicar si es o no múltiplo de 3.


#include <stdio.h>

int main(){
	int num;
	
	printf("Introduzca un numero: ");
	scanf("%d", &num);
	
	if(num % 2 == 0)
		printf("El numero es par ");
    if(num %3 == 0)
		printf("\nY tambien es multiplo de tres");
	else
		printf("\nPero no es multiplo de tres");
	
	return 0;
				
}