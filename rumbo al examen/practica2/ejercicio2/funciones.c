#include<stdlib.h>
#include<stdio.h>

#include "funciones.h"

int * reservaMemoria(int elementos){

	int * puntero=NULL;
	
	puntero=(int *)malloc(sizeof(int)*elementos);

	if(!puntero){
		printf("\nError reservando memoria...\n");
		exit(-1);
	}
	
	return puntero;
}

void rellenaVector(int * vector,int elementos){
	
	int i;

	for(i=0;i<elementos;i++){
		vector[i]=rand()%10;
	}
}


void imprimeVector(int * vector,int elementos){

	int i;

	printf("\nImprimendo vector: ");
	
	for(i=0;i<elementos;i++){
		printf("[%d]",vector[i]);
	}
	
	printf("\n");
}

void extraeImpares(int ** vector,int * elementos){

	int i,j=0,* auxiliar=NULL;
	
	auxiliar=reservaMemoria(*elementos);

	for(i=0;i<(*elementos);i++){
		if((*vector)[i]%2!=0){
			auxiliar[j]=(*vector)[i];
			j++;
		}
	}
	
	free(*vector);

	auxiliar=(int *)realloc(auxiliar,j*sizeof(int));

	*elementos=j;
	*vector=auxiliar;

}

void liberaMemoria(int ** vector){
	free(*vector);
	*vector=NULL;
}
