/*Escriba un programa que calcule el área de un triángulo rectángulo, pidiendo al
usuario la altura y la base. La salida por pantalla debe ser "Un triangulo rectángulo de
altura ____ y base ____, tiene un área de ____" (sustituyendo los espacios en blanco
por los valores)
NOTA area = (base * altura)/2*/

#include <stdio.h>

int main(){
	int altura, base, area;
	
	printf("Introduzca el valor de la altura: ");
	scanf("%d", &altura);
	
	printf("\nIntroduzca el valor de la base: ");
	scanf("%d", &base);
	
	area=(altura*base)/2;
	
	printf("\nUn triangulo rectangulo de altura %d y base %d, tiene un area de %d: ",altura,base,area);
	
	
	return 0;
	
	
	

}		
	
	

