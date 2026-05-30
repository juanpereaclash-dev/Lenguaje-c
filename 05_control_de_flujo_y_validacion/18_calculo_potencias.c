/*Escriba un programa que eleve un número a una potencia, utilizando dos métodos: a)
utilizando la función potencia y b) usando un bucle, sin recurrir al operador potencia.
Nota: En C, para poder usar la función potencia (pow(x, y)=x
y
) es necesario incluir la
biblioteca math (#include <math.h>). */

#include <stdio.h>
#include <math.h>

int main(){
	float num,res1, res2;
	int i, p;

	printf("Introduzca un numero: ");
	scanf("%f", &num);
	
	printf("A que potencia lo desea elevar: ");
	scanf("%d", &p);
	
	res1=res1+1;
	
	for(i=1; i<=p; i++)
    res1=res1 * num;
    
    res2= pow (num,p);
    
    printf("por el primer metodo el resultado es %8.2f y por el segundo %8.2f \n", res1, res2);

    return 0;
    
}