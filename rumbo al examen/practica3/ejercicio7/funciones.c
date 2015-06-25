#include<stdio.h>
#include<stdlib.h>

#include "funciones.h"

void trim(char * nombre){
	
	FILE * fichero=NULL, * temporal=NULL;
	char auxiliar;	
	int contador=0;

	fichero=fopen(nombre,"r");
	temporal=fopen("temporal.txt","w");

	if(!fichero || !temporal){
		printf("\nError abriendo ficheros...\n");
		exit(-1);
	}

	while((auxiliar=fgetc(fichero))!=EOF){
		if(auxiliar==' '){
			if(contador==0){
				contador+=1;//Numero de espacios incrementados
				fputc(auxiliar,temporal);
			}
		}
		else{
			fputc(auxiliar,temporal);
			contador=0;
		}		
	}

	fclose(fichero);
	fclose(temporal);
	
	remove(nombre);
	rename("temporal.txt",nombre);

}

