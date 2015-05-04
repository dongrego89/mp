#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "ej7.h"

void trimEspacio(char * nombre){

	FILE * origen=NULL, * destino=NULL;
	char nombreDestino[MAX_FILENAME], c;
	int espacios=0;

	strcpy(nombreDestino,nombre);
	strcat(nombreDestino,".tmp");

	origen=fopen(nombre,"r");
	if(!origen){
		printf("\nError abriendo fichero\n");
		exit(-1);
	}

	destino=fopen(nombreDestino,"w");
	if(!destino){
		printf("\nError abriendo fichero\n");
		exit(-1);
	}

	while((c=fgetc(origen))!=EOF){
		if((c==' ') && (espacios==0)){
			fputc(c,destino);
			espacios++;
		}
		if(c!=' '){
			espacios=0;
			fputc(c,destino);
		}
	
	}

	fclose(origen);
	fclose(destino);

	remove(nombre);
	rename(nombreDestino,nombre);
	
}

void imprimeFichero(char * nombre){

	FILE * fichero=NULL;
	char cadena[MAX_CHAR];

	fichero=fopen(nombre,"r");
	if(!fichero){
		printf("\nError abriendo fichero\n");
		exit(-1);
	}
	
	while((fgets(cadena,MAX_CHAR,fichero))!=NULL){
		printf("%s",cadena);	
	}
	
	fclose(fichero);
}
