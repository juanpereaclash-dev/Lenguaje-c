//JuanPerea

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h> 
#include <conio.h> 
#include <string.h>

#define MAX_ERRORES 5
#define MAX_PALABRAS 10
#define MAX_CATEGORIAS 7
#define MAX_PISTA 100
#define MAX_COMODINES 1 

typedef struct {
    char palabra[50];
    char pista[MAX_PISTA];
    int valor;
    int comodines_disponibles; 
    int pistas_disponibles; 
} PalabraConPista;

typedef struct {
    char tema[50];
    PalabraConPista palabras[MAX_PALABRAS];
    int num_palabras;
} Tema;

PalabraConPista seleccionar_palabra(Tema *tema) {
    int index = rand() % tema->num_palabras;
    return tema->palabras[index];
}

void mostrar_dibujo(int errores) {
    const char *dibujo[] = {
     "\n     _______\n    |       |\n    |\n    |\n    |\n    |\n    |\n ----------",
       "\n     _______\n    |       |\n    |       0\n    |       |\n    |\n    |\n    |\n ----------",
       "\n     _______\n    |       |\n    |       0\n    |      /|\n    |\n    |\n    |\n ----------",
       "\n     _______\n    |       |\n    |       0\n    |      /|\\\n    |\n    |\n    |\n ----------", 
       "\n     _______\n    |       |\n    |       0\n    |      /|\\\n    |      /\n    |\n    |\n ----------",
	   "\nÂ  Â  Â _______\nÂ  Â  |Â  Â  Â  Â |\nÂ  Â  |Â  Â  Â  Â 0\nÂ  Â  |Â  Â  Â  /|\\\nÂ  Â  |Â  Â    / \\\nÂ  Â  |\nÂ  Â  |\n ----------" 
    };
    if (errores >= 0 && errores < MAX_ERRORES) {
        printf("%s\n", dibujo[errores]);
    }
}

void mostrar_palabra(char *palabra, char *adivinadas) {
    for (int i = 0; i < strlen(palabra); i++) {
        if (strchr(adivinadas, palabra[i]) || palabra[i] == ' ') {
            printf("%c ", palabra[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int manejar_intento(char letra, char *palabra, char *adivinadas, int *errores) {
    if (strchr(adivinadas, letra)) {
        return 0; 
    }

    int acierto = 0;
    for (int i = 0; i < strlen(palabra); i++) {
        if (palabra[i] == letra) {
            acierto = 1;
        }
    }

    if (acierto) {
        strncat(adivinadas, &letra, 1);
        return 1;
    } else {
        (*errores)++;
        return 0;
    }
}

void usar_comodin(char *palabra, char *adivinadas) {
    for (int i = 0; i < strlen(palabra); i++) {
        if (palabra[i] != ' ' && !strchr(adivinadas, palabra[i])) {
            printf("El comod%cn revela la letra: %c\n", 161, palabra[i]);
            strncat(adivinadas, &palabra[i], 1);
            return;
        }
    }
    printf("No hay letras desconocidas para revelar.\n");
}

void refrescar_pantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void mostrar_titulo_y_datos(Tema *tema, PalabraConPista *palabra, int palabras_jugadas, int comodines_acumulados, int palabras_correctas, int palabras_incorrectas) {
    refrescar_pantalla();
    printf(" Juego del Ahorcado\n");
    printf("=====================================\n");
    printf("Tema: %s\n", tema->tema);
    printf("Palabra: ");
    mostrar_palabra(palabra->palabra, "");
    printf("Palabras Jugadas: %d\n", palabras_jugadas);
    printf("Comodines Disponibles: %d\n", palabra->comodines_disponibles);
    printf("Pistas Disponibles: %d\n", palabra->pistas_disponibles);
    printf("Comodines Acumulados: %d\n", comodines_acumulados);
    printf("Palabras correctas: %d\n", palabras_correctas);
    printf("Palabras incorrectas: %d\n", palabras_incorrectas);
    printf("=====================================\n");
}

void juego_ahorcado(Tema *tema) {
    int palabras_correctas = 0;
    int comodines_acumulados = 0;
    int palabras_jugadas = 0;
    int errores = 0;
    int comodines_restantes = MAX_COMODINES; 
    int pistas_restantes = 1; 
    int palabras_incorrectas = 0;
    int seleccion;
    for (int i = 0; i < tema->num_palabras; i++) {
        PalabraConPista *palabra = &tema->palabras[i];
        char adivinadas[50] = {0};
        int errores = 0;
        char letra;
        char opcion;
        int pista_mostrada = 0;
        

        palabra->comodines_disponibles = comodines_restantes; 
        palabra->pistas_disponibles = pistas_restantes; 

        mostrar_titulo_y_datos(tema, palabra, palabras_jugadas, comodines_acumulados, palabras_correctas, palabras_incorrectas);

        while (errores < MAX_ERRORES) {
            mostrar_dibujo(errores);
            mostrar_palabra(palabra->palabra, adivinadas);
            printf("Errores: %d/%d\n", errores, MAX_ERRORES);

            
            printf("Introduce una letra o un atajo (0: comod%cn, =: pista): ", 161 );
            scanf(" %c", &opcion);
            opcion = tolower(opcion);

            if (opcion == '0') {
                if (palabra->comodines_disponibles > 0) {
                    usar_comodin(palabra->palabra, adivinadas);
                    palabra->comodines_disponibles--;
                    comodines_acumulados++;
                } else {
                    refrescar_pantalla();
                    printf("No hay comodines disponibles.\n");
                }
                continue;
            } else if (opcion == '=') {
                if (palabra->pistas_disponibles > 0) {
                    printf("Pista: %s\n", palabra->pista);
                    palabra->pistas_disponibles--;
                    pista_mostrada = 1;
                } else {
                    refrescar_pantalla();
                    printf("No hay pistas disponibles.\n");
                }
                continue;
            }

            letra = opcion;

            if (manejar_intento(letra, palabra->palabra, adivinadas, &errores)) {
                printf("Correcto\n");
            } else {
                printf("Incorrecto.\n");
            }

            int palabra_completada = 1;
            for (int j = 0; j < strlen(palabra->palabra); j++) {
                if (palabra->palabra[j] != ' ' && !strchr(adivinadas, palabra->palabra[j])) {
                    palabra_completada = 0;                   
					break;	
									  				                  
                }
            }

            if (palabra_completada) {
                printf("Ganaste, La palabra es: %s\n", palabra->palabra);
                printf("Presiona una tecla para ir a la siguiente palabra..");
				getch();
				palabras_correctas++;
                palabras_jugadas++;
				break;
				
            }
				
			
            	

            if (errores >= MAX_ERRORES) {
                printf("Perdiste. La palabra era: %s\n", palabra->palabra);
                printf("Presiona una tecla para ir a la siguiente palabra..");
                getch();
                palabras_incorrectas++;
				palabras_jugadas++;
				
            }

            refrescar_pantalla(); 
        }

       
        comodines_restantes = palabra->comodines_disponibles;
        pistas_restantes = palabra->pistas_disponibles;
	

	}
    if(palabras_correctas >= 3 ){
	printf("Enhorabuena usted a ganado \n");
        
    }else 
	printf("Buena Suerte para la proxima \n");
	
	printf("Palabras completadas correctamente: %d/%d\n", palabras_correctas, tema->num_palabras);
    printf("Palabras no completadas : %d/%d\n", palabras_incorrectas, tema->num_palabras);
	printf("Comodines acumulados: %d\n", comodines_acumulados);   
  	getch();
 }



int main() {
    int opccion_valida = 0;
	srand(time(NULL)); 
    
    
    Tema temas[MAX_CATEGORIAS] = {
        {"Frutas", {
            {"manzana", "Fruta roja y crujiente", 7},
            {"naranja", "Fruta cÃ­trica y jugosa", 7},
            {"banana", "Fruta amarilla y dulce", 6},
            {"pera", "Fruta verde o amarilla y jugosa", 4},
            {"mango", "Fruta tropical y dulce", 5},
        }, 5},
        {"Animales", {
            {"perro", "Animal domestico conocido como el mejor amigo del hombre", 4},
            {"gato", "Animal domestico conocido por su independencia", 3},
            {"elefante", "Animal grande con trompa y orejas grandes", 8},
            {"tigre", "Gran felino con rayas negras y naranjas", 5},
            {"oso", "Animal grande y peludo, a menudo visto en bosques", 3},
            
        }, 5},
        {"Colores", {
            {"rojo", "Color primario asociado con la pasion", 4},
            {"azul", "Color primario asociado con el cielo y el mar", 4},
            {"verde", "Color asociado con la naturaleza y la vegetacion", 5},
            {"amarillo", "Color brillante asociado con el sol", 7},
            {"negro", "Color oscuro asociado con la elegancia", 5},          
        }, 5},
        {"Ciudades", {
            {"paris", "Capital de Francia, conocida por la Torre Eiffel", 5},
            {"londres", "Capital del Reino Unido, conocida por el Big Ben", 7},
            {"tokyo", "Capital de Japon, conocida por su modernidad y cultura", 5},
            {"madrid", "Capital de Espa�a, conocida por el Prado", 6},
            {"roma", "Capital de Italia, conocida por sus ruinas antiguas", 4},   
        }, 5},
        {"Deportes", {
            {"futbol", "Deporte jugado con una pelota en un campo rectangular", 6},
            {"baloncesto", "Deporte jugado con una pelota en una cancha y aros", 9},
            {"tenis", "Deporte jugado con raquetas y una pelota en una cancha", 5},
            {"natacion", "Deporte en el que se nada en el agua", 8},
            {"ciclismo", "Deporte en el que se usa una bicicleta", 7},
        }, 5},
        {"Peliculas", {
            {"inception", "Pelicula sobre sue�os y realidades alternativas", 9},
            {"avatar", "Pelicula de ciencia ficcion en Pandora", 6},
            {"matrix", "Pelicula sobre un mundo simulado", 6},
            {"titanic", "Pelicula sobre el hundimiento de un famoso barco", 7},
            {"joker", "Pelicula sobre el villano de Batman", 5},
        }, 5},
        {"Musica", {
            {"rock", "Genero musical con guitarra electrica y bateria", 4},
            {"pop", "Genero musical popular y pegajoso", 3},
            {"jazz", "Genero musical improvisado y complejo", 4},
            {"blues", "Genero musical con raÃ­ces en la tristeza y el lamento", 5},
            {"reggae", "Genero musical originario de Jamaica con ritmo relajado", 6},
        }, 5}
    };
    int repetir;
    
    int seleccion;
    do{
    printf(" Juego del Ahorcado\n");
    printf("=====================================\n");
    printf("Selecciona un tema:\n");
    for (int i = 0; i < MAX_CATEGORIAS; i++) {
        printf("%d. %s (%d palabras)\n", i + 1, temas[i].tema, temas[i].num_palabras);
    }
    printf("Introduce el n%cmero del tema: ",163);
    scanf("%d", &seleccion);
    
	
	if (seleccion < 1 || seleccion > MAX_CATEGORIAS) {
        printf("Seleccion inv%clida.\n",160);
        opccion_valida = 1;
    }else{
    	opccion_valida = 0;}
	} while (opccion_valida == 1);
	
    
	juego_ahorcado(&temas[seleccion - 1]);
   
    return 0;
}
