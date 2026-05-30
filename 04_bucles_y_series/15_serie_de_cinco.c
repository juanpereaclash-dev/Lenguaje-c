/*Escriba un programa en C que genere la siguiente serie: 5,10,15,20,25,30… El
programa preguntará primero cuantos términos se quieren mostrar y después mostrará
la serie correspondiente.*/

#include <stdio.h>

int main(){
	int n, s;
	
	printf("Introduzca el numero de terminos: " );
	scanf("%d", &s);
	
	for (n=1; n <= s; n ++)
	printf("%d\n",n*5);
			
	return 0;
}