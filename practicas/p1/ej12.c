#include<stdlib.h>
#include<stdio.h>
#include "ej12.h"

void leerMatriz(int * m, int nfil, int ncol){

	int i,j;

	for(i=0;i<nfil;i++){
		for(j=0;j<ncol;j++){
			printf("\tMatriz[%d][%d]: ",i,j);
			scanf("%d",&m[i*ncol+j]);
		}
	}
}

void escribirMatriz( int * m, int nfil, int ncol){
	int i,j;
	
	for(i=0;i<nfil;i++){
		for(j=0;j<ncol;j++){
			printf("\tMatriz[%d][%d]: %d\n",i,j,m[i*ncol+j]);
		}
	}
	
	

}


int * reservaMemoria(int tamano){
	int * puntero=NULL;

	puntero=(int *)malloc(sizeof(int)*tamano);

	if(puntero==NULL){
		printf("\nError reservando memoria");
		exit(-1);
	}

	return puntero;
}
