#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#include "ej10.h"


void imprimeFichero(char * n){
	
	FILE * fichero=NULL;
	char auxiliar[MAX_CHAR];

	fichero=fopen(n,"r");

	if(!fichero){
		printf("\nError en la apertura del fichero\n");
		exit(-1);
	}

	while((fgets(auxiliar,MAX_CHAR,fichero))!=NULL){
		printf("%s",auxiliar);
	}

	fclose(fichero);
}

int capitalizaFichero(char * n){

	FILE * origen=NULL,* destino=NULL;
	char c;
	char n2[MAX_FILENAME];

	strcpy(n2,"mayusculas-");// Preparando el nombre destino para el fichero transformado
	strcat(n2,n);

	origen=fopen(n,"r");
	if(!origen){
		printf("\nError en la apertura del fichero\n");
		exit(-1);
	}
	
	destino=fopen(n2,"w");
	if(!destino){
		printf("\nError en la apertura del fichero\n");
		exit(-1);

	}

	
	while((c=fgetc(origen))!=EOF){
		fputc(toupper(c),destino);
	}

	fclose(origen);
	fclose(destino);

	return 1;
}
