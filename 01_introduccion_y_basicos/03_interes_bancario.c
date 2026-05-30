/*Escriba un programa que calcule el interés que se obtiene por un determinado dinero
depositado en un banco. Para ello el programa preguntará por el capital inicial y por el
tipo de interés.*/


#include <stdio.h>

int main(){
	float capital_inicial, interes, capital_final, porcentaje;
	
	printf("Cual es el capital inicial del que parte?");
	scanf("%f", &capital_inicial);
	
	printf("\nCual es el interes anual aplicado?");
	scanf("%f", &porcentaje);
	
	interes=porcentaje/100;

	capital_final=capital_inicial+(interes*capital_inicial);
	
	printf("\nEl capital final despues de un anio sera: %.2f",capital_final);
	
	return 0;
	
}