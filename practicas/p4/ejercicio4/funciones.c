#include<stdio.h>
#include<stdlib.h>

#include "funciones.h"

void * reservaMemoria(int elementos,char opcion){
	void * puntero=NULL;
	switch(opcion){
		case 'i':
			puntero=(void *)malloc(sizeof(int)*elementos);
		break;
		case 'l':
			puntero=(void *)malloc(sizeof(long int)*elementos);
		break;
		case 'f':
			puntero=(void *)malloc(sizeof(float)*elementos);
		break;
		case 'd':
			puntero=(void *)malloc(sizeof(double)*elementos);
		break;
	}
	if(!puntero){
		printf("\nError reservando memoria\n");
		exit(-1);
	}
	return puntero;
}


void imprimeVector(void * vector,int elementos,char opcion,char * mensaje){
	int i;
	printf("%s",mensaje);

	for(i=0;i<elementos;i++){
		switch(opcion){
			case 'i':
				printf("\n\tElemento[%2d]: %2d",i,((int *)vector)[i]);
			break;
			case 'l':
				printf("\n\tElemento[%2d]: %ld",i,((long int *)vector)[i]);
			break;
			case 'f':
				printf("\n\tElemento[%2d]: %f",i,((float *)vector)[i]);
			break;
			case 'd':
				printf("\n\tElemento[%2d]: %lf",i,((double *)vector)[i]);
			break;
		}
	}

	printf("\n");
}

void rellenaVectorAleatorio(void * vector,int elementos,char opcion){

	int i;

	switch(opcion){
			case 'i':
				for(i=0;i<elementos;i++){
					((int *)vector)[i]=rand()%10;
				}
			break;
			case 'l':
				for(i=0;i<elementos;i++){
					((long int *)vector)[i]=rand()%100 * 100000;
				}
			break;
			case 'f':
				for(i=0;i<elementos;i++){
					((float *)vector)[i]=rand()%1000 / 10;
				}
			break;
			case 'd':
				for(i=0;i<elementos;i++){
					((double *)vector)[i]=rand()%1000 / 10;
				}
			break;
		}
}
