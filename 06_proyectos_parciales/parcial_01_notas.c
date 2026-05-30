//Realizar el algoritmo para evaluarlos en este semestre. Sin utilizar ninguna estructura de control.


#include <stdio.h>

int main(){

float parcial1, parcial2, proyecto, nota_final;

printf("\nIntroduzca la primera nota: "); scanf("%f", &parcial1);
printf("\nIntroduzca la segunda nota: "); scanf("%f", &parcial2);
printf("\nIntroduzca la tercera nota: "); scanf("%f", &proyecto);

nota_final= (parcial1*0.25) + (parcial2*0.25) + (proyecto*0.50);

printf("\nLa nota del semestre es de: %f", nota_final);
 
return 0;
	
}