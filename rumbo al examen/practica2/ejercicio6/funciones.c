#include<stdlib.h>
#include<stdio.h>

#include "funciones.h"

int ** reservarMemoria (int nFil, int nCol){

	int i,** puntero=NULL;
	

	puntero=(int **)malloc(sizeof(int *)*nFil);

	if(!puntero){
		printf("\nError reservando memoria para filas de matriz...");
		exit(-1);
	}	
	for(i=0;i<nFil;i++){
		puntero[i]=(int *)malloc(sizeof(int)*nCol);
			if(!puntero[i]){
				printf("\nError reservando memoria para columnas de matriz...");
				exit(-1);
			}	
	}
	return puntero;
}

void rellenaMatriz (int **matriz, int nFil, int nCol){

	int i,j;

	for(i=0;i<nFil;i++){
		for(j=0;j<nCol;j++){
			matriz[i][j]=i+j;
		}
	}
}

void imprimeMatriz (int **matriz, int nFil, int nCol){
	
	int i,j;

	printf("\n");
	
	for(i=0;i<nFil;i++){
		printf("\t");
		for(j=0;j<nCol;j++){
		//	printf("[%d]",matriz[i][j]);
			printf("[%d]",*(*(matriz+i)+j));
		}
		printf("\n");
	}
}

int ** eliminarFila (int **matriz, int nFil, int nCol, int fila_borrada){

	int i,j,** auxiliar=NULL;

	auxiliar=reservarMemoria(nFil,nCol);
	
	j=0;
	
	for(i=0;i<nFil;i++){
		if(i!=fila_borrada){
			auxiliar[j]=matriz[i];
			j+=1;
		}
		else{
			free(matriz[i]);
			matriz[i]=NULL;
		}
	}	
	auxiliar=(int **)realloc(auxiliar,sizeof(int *)*j);
	return auxiliar;
}
void liberarMemoria(int ***matriz, int nFil){
	
	int i;

	for(i=0;i<nFil;i++){
		free((*matriz)[i]);
	}
	free(*matriz);
	*matriz=NULL;
}
