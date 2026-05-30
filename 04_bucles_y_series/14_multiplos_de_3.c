/*Escriba un programa que muestre en pantalla todos los múltiplos de 3 entre los
números 1 y 100.*/

#include <stdio.h>

int main(){
	int n;
	
	for (n=3; n<=100; n += 3)
	printf("%d\n",n);
	
	return 0;
	
	
	
}