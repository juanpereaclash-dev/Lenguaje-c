/*Escriba un programa en C que muestre por pantalla el valor de una entrada de cine en
función de los años de la persona. Así, el precio es de 7 Euros, pero si el usuario tiene
menos de 5 años se aplica un 60% de descuento, y si es mayor de 60 años, se aplicará
un descuento del 55 %. El precio de la entrada se debe declarar como una constante*/


#include <stdio.h>

int main(){
	int precio= 7, edad, total;
	
	printf("Introduzca su edad: ");
	scanf("%d", &edad);
	
	if(edad < 5)
		total = precio*0.4;		
	else if(edad > 60)
		total = precio*0.45;			
	else
		total= precio;
		
	printf("El valor de su entrada es de: %d ",total );	
	
	return 0;
	
}