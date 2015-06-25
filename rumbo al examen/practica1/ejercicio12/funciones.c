#include<stdlib.h>
#include<stdio.h>

#include "funciones.h"


int * reservaMemoria(int elementos){

	int * puntero=NULL;
	
	puntero=(int *)malloc(sizeof(int)*elementos);

	if(!puntero){
		printf("\nError reservando memoria\n");
		exit(-1);
	}
	return puntero;
}

void leeMatriz(int * matriz,int filas,int columnas){

	int i,j;
	
	printf("\nLeyendo matriz:\n");

	for(i=0;i<filas;i++){
		for(j=0;j<columnas;j++){
			printf("\tMatriz[%d][%d]: ",i,j);
			scanf("%d",matriz+(i*columnas)+j);
			getchar();
		}
	}
	printf("\n");
}

void escribeMatriz(int * matriz,int filas,int columnas){

	int i,j;

	printf("\nImprimiendo matriz:\n");

	for(i=0;i<filas;i++){
		for(j=0;j<columnas;j++){
			printf("\n\tMatriz[%d][%d]: %d",i,j,*(matriz+(i*columnas)+j));
		}
	}

	printf("\n");
}

void liberaMemoria(int ** matriz){
	free(*matriz);
	*matriz=NULL;
}
