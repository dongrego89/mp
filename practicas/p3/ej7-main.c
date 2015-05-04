#include<stdio.h>

#include "ej7.h"

int main(){

	char nombre[MAX_FILENAME];
	printf("\nIntroduce el nombre del fichero al que normalizar espaciado: ");
	gets(nombre);

	imprimeFichero(nombre);

	trimEspacio(nombre);
	
	imprimeFichero(nombre);

	return 0;
}
