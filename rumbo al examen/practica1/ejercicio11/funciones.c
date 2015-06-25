#include<stdio.h>

#include "funciones.h"

void leeValores(double * vector, int * elementos){
	
	int i;

	printf("\n¿Que numero de valores utilizarás en el vector?");
	scanf("%d",elementos);
	getchar();

	printf("\nRellenando el vector: \n");
	for(i=0;i<*elementos;i++){
		printf("\t[*]Introduce Valores[%d]: ",i);
		scanf("%lf",vector+i);
		getchar();
	}	
}

void escribeValores(double * vector, int elementos){

	int i;
	printf("\n");
	for(i=0;i<elementos;i++){
		printf("\nValores[%d]: %lf",i,vector[i]);
	}
	printf("\n");
}

double mediaValores(double * vector, int elementos){

	double resultado=0;
	int i;
	
	for(i=0;i<elementos;i++){
		resultado+=vector[i];
	}
	return resultado / (double) elementos;
}
