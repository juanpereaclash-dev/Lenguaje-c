/*Escriba un programa en el que se declaren tres variables, a, b y c y se asigne a esas
variables los valores 5, 7 y 9 respectivamente. El programa deberá entonces calcular
su suma y mostrar el resultado. Modifíquelo para que los valores de las variables sean
introducidos por el usuario.*/

#include <stdio.h>

int main (){
	int a, b, c, suma;
	
	printf("\n Introduzca el valor del primer numero: ");
	scanf("%d", &a);
	
	printf("\n Introduzca el valor del segundo numero:");
	scanf("%d", &b);
	
	printf("\n Introduzca el valor del tercer numero:");
	scanf("%d", &c);
	
	suma=a+b+c;
	
	printf("\n El resultado de la suma de numeros es de: %d ",suma);
	
	return 0;
	
	
	
}