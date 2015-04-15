#include<stdio.h>
#include<stdlib.h>

#include "ej4.h"

int * reservaMemoria(int elementos){
	int * puntero=NULL;
	
	puntero=(int *)malloc(sizeof(int)*elementos);
	
	if(puntero==NULL){
		printf("\nError reservando memoria\n");
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

void imprimeVector(int * vector,int elementos,char * mensaje){
	int i;

	printf("%s",mensaje);
	for(i=0;i<elementos;i++){
		printf("[%.0d]",vector[i]);
	}
	printf("\n");
}
