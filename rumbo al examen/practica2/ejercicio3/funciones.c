#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "funciones.h"

ficha * reservaMemoria(int elementos){

	ficha * puntero=NULL;
	
	puntero=(ficha *)malloc(sizeof(ficha)*elementos);

	if(!puntero){
		printf("\nError reservando memoria\n");	
		exit(-1);
	}

	return puntero;
}

void rellenaVector(ficha * vector, int elementos){
	
	int i;

	for(i=0;i<elementos;i++){
		printf("\n[+]Registrando elemento %d",i);
		rellenaElemento(vector+i);
	}

}

void rellenaElemento(ficha * estructura){
	
	printf("\n\tIntroduce el nombre: ");
	fgets(estructura->nombre,MAX_CHAR,stdin);
	acondicionaCadena(estructura->nombre);

	printf("\tIntroduce la estatura: ");
	scanf("%d",&(estructura->estatura));
	getchar();

	printf("\tIntroduce el peso: ");
	scanf("%f",&(estructura->peso));
	getchar();

	printf("\tIntroduce el dorsal: ");
	scanf("%d",&(estructura->dorsal));
	getchar();

}


void acondicionaCadena(char * cadena){

	if(cadena[strlen(cadena)-1]=='\n'){
		cadena[strlen(cadena)-1]='\0';
	}

}

void imprimeVector(ficha * vector, int elementos){

	int i;
	
	for(i=0;i<elementos;i++){
		printf("\n\tNombre: %s",vector[i].nombre);
		printf("\n\tDorsal: %d",vector[i].dorsal);
		printf("\n\tPeso: %.3f\tEstatura: %d",vector[i].peso,vector[i].estatura);
	}
	printf("\n");
}

void borraPorCaracter(ficha ** vector, int * elementos, char caracter){
	
	int i,validos=0;
	ficha * auxiliar=NULL;

	auxiliar=reservaMemoria(*elementos);

	for(i=0;i<*elementos;i++){
		if(strchr((*vector)[i].nombre,caracter)==NULL){//Si no ha habido coincidencia con el caracter
			auxiliar[validos]=(*vector)[i];
			validos+=1;
		}
	}

	free(*vector);
	*elementos=validos;

	auxiliar=(ficha *)realloc(auxiliar,sizeof(ficha)*validos);	
	*vector=auxiliar;

}

void liberaMemoria(ficha ** vector){
	free(*vector);
	*vector=NULL;
}
