#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "ej10.h"

int main(int argc, char ** argv){
	
	char cadena[MAX_FILENAME];

	if(argc!=2){
		printf("\nError en la invocación, se debe invocar así:\n\t%s [NOMBRE FICHERO]\n",argv[0]);
		exit(-1);
	}

	imprimeFichero(argv[1]);
	capitalizaFichero(argv[1]);

	strcpy(cadena,"mayusculas-");
	strcat(cadena,argv[1]);

	imprimeFichero(cadena);
		

	return 0;
}
