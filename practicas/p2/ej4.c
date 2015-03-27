#include<stdio.h>
#include<stdlib.h>

#include "ej4.h"

int ** reservaMemoria(int f,int c){
	int ** puntero=NULL,i;

	puntero=(int **)malloc(sizeof(int *)* f);
	if(puntero==NULL){
		printf("\nError reservando memoria\n");
		exit(-1);
	}	
	
	for(i=0;i<f;i++){
		*(puntero+i)=(int *)malloc(sizeof(int)*c);
		if(*(puntero+i)==NULL){
			printf("\nError reservando memoria\n");
			exit(-1);
		}
	}
	
	return puntero;
}

void rellenaMatriz(int ** matriz, int f, int c){
	int i,j;

	for(i=0;i<f;i++){
		for(j=0;j<c;j++){
			*(*(matriz+i)+j)=rand()%10;
		}
	}
}


void imprimeMatriz(int ** matriz,int f,int c,char * mensaje){
	int i,j;
	
	printf("%-15s\n",mensaje);

	for(i=0;i<f;i++){
		printf("\tF%d",i );
		for(j=0;j<c;j++){
			printf("[%02d]",*(*(matriz+i)+j));
		}
		printf("\n");
	}
}


int ** eliminaFila(int ** matriz,int f, int c, int fb){
	int ** puntero=NULL,i,j,contador;
	puntero=reservaMemoria(f,c);

	for(i=0,contador=0;i<f;i++){
		if(i!=fb){
			for(j=0;j<c;j++){
				*(*(puntero+contador)+j)=*(*(matriz+i)+j);
			}
		contador+=1;
		}
		else{
			free(*(matriz+i));
			*(matriz+i)=NULL;
		}
	}
	return puntero;
}


void liberaMemoria(int *** matriz, int f){
	int i,j;
	
	for(i=0;i<f;i++){

		free(*((*matriz)+i));
		*((*matriz)+i)=NULL;	

		free(*(*matriz+i));
		*(*matriz+i)=NULL;
	}

	*matriz=NULL;

}

