/*Escriba un programa que calcule el perímetro de una circunferencia.
NOTA perimetro = 2 * PI * r). Se recomienda definir PI como una constante
usando la directiva define.*/


#include <stdio.h>
#define PI 3.1416

int main(){
	float radio, perimetro;
	
	printf("Introduzca el valor del radio: ");
	scanf("%f", &radio);
	
	perimetro=2*PI*radio;
	
	printf("El valor del perimetro es de: %.2f ",perimetro);
	
	
	return 0;
	
	
	
}