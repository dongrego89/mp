#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "ej8.h"


persona * reservaMemoria(int n){
	persona * puntero=NULL;
	puntero=(persona *)malloc(sizeof(persona)*n);

	if(puntero==NULL){
		printf("\nError reservando memoria\n");
		exit(-1);
	}
	else{
		return puntero;
	}
}


void escribirPersona(persona * p){
	limpiar();
	printf("Introduce el nombre: ");
	gets(p->nombre);
	printf("Introduce los apellidos: ");
	gets(p->apellidos);
	printf("Introduce la edad: ");
	scanf("%d",&(p->edad));
	printf("Introduce el sexo (V/M): ");
	scanf("%c",&(p->sexo));
	limpiar();
}

void limpiar(){
	getchar();
	fflush(stdin);
}
