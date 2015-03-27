#include<stdio.h>
#include<stdlib.h>

#include "ej2.h"

int * reservaMemoria(int elementos){
	int * puntero=NULL;
	puntero=(int *)malloc(sizeof(int)*elementos);

	if(puntero!=NULL){
		return puntero;
	}
	else{
		printf("\nError reservando memoria\n");
		exit(-1);
	}
}

int * extraeImpares(int * vector, int elementos, int * nElementos){
	int * puntero=NULL,i;
	
	puntero=reservaMemoria(elementos);

	for(i=0,(*nElementos)=0;i<elementos;i++){
		if(*(vector+i)%2!=0){
			*(puntero+(*nElementos))=*(vector+i);
			*nElementos=(*nElementos)+1;
		}
	}

	puntero=realloc(puntero,(*nElementos));

	if(puntero==NULL){
		if((*nElementos==elementos) || (*nElementos==0)){
			return puntero;
		}
		else{
			printf("\nError relocalizando memoria\n");
			exit(-1);
		}
	}
	else{
		return puntero;
	}
}


void imprimeVector(int * vector, int elementos, char * mensaje){
	int i;
	
	printf("\n%-15s:",mensaje);	
	
	for(i=0;i<elementos;i++){	
		printf("[%d]",*(vector+i));
	}

	printf("\n");
}

void rellenaVector(int * vector, int elementos){
	int i;
	
	for(i=0;i<elementos;i++){
		*(vector+i)=rand()%10;
	}
}
