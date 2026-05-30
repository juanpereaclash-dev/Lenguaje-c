/*Escriba un programa que pida al usuario su nombre y contraseña y le de tres
oportunidades para introducir los datos correctos, que serán root y 1234. Si los datos
introducidos son correctos se mostrará por pantalla “Bienvenido al sistema”. En caso
contrario se mostrará un mensaje por pantalla indicando que se ha superado el número
de intentos permitido.
Notas:
Puesto que las cadenas de caracteres finalizan con el carácter nulo (‘\0’), usuario y
contraseña se declararán como cadenas de longitud 5 (char usuario[5]). Para leer
cualquiera de estas cadenas con la función scanf se usará el descriptor de formato %s y
dado que el nombre de la cadena ya es una dirección, éste no debe ir precedido del
símbolo &(scanf(“%s”, usuario)).
Para comparar cadenas se debe usar la función strcmp (string compare), por ejemplo
strcmp(usuario, "root"), que devolverá un 0 si las cadenas son iguales y otro valor si
son distintas.*/


#include <stdio.h>
#include <cstring>


int main(){
	
	char user[5], pass[5];
	int correcto = 0;
	int intentos = 0;
	
	do{
		printf("Introduzca el usuario: ");
		scanf("%s", user);
		
		printf("Introduzca la contrasenia: ");
		scanf("%s", pass);
		
		if ((strcmp(user, "root")==0) && (strcmp(pass, "1234")==0))
 		correcto=1;
 		else
 		intentos=intentos+1;
		
	}while( (intentos < 3) && (correcto == 0) );
	
	if (intentos==3)
	printf ("Se ha superado el numero maximo de intentos permitido\n");
 	else 
 	printf ("Bienvenido al sistema\n");
 	
 	return 0;
}
