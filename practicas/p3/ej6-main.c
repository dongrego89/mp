#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "ej6.h"

int main(int argc, char ** argv){
	
	char cadena[MAX_FILENAME];
	char fichero[MAX_FILENAME];

	printf("Introduce el nombre del fichero a convertir: ");
	gets(fichero);

	imprimeFichero(fichero);
	capitalizaFichero(fichero);

	strcpy(cadena,"mayusculas-");
	strcat(cadena,fichero);

	imprimeFichero(cadena);
		

	return 0;
}
