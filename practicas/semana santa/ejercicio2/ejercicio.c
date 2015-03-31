/**--------------------------------------------------------------------------------------------------------------
	
	@file ejercicio.c
	@brief Documento con las funciones del ejercicio
	@author Grego Corpas Prieto
	@date 30-03-2015
	@version 1.0
	
--------------------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

#include "ejercicio.h"

int ** creaMatriz(int fil, int col){
	int i;
	int ** puntero=NULL;

	puntero=(int **)malloc(sizeof(int *)*fil);
	
	if(puntero==NULL){
		printf("\nError reservando memoria\n");
		exit(-1);
	}
	
	for(i=0;i<col;i++){
		puntero[i]=(int *)malloc(sizeof(int)*col);

		if(puntero[i]==NULL){
			printf("\nError reservando memoria\n");
			exit(-1);
		}
	}
	return puntero;
}

int * creaVector(int e){
	int * puntero=NULL;
	
	puntero=(int *)malloc(sizeof(int)*e);
	
	if(puntero==NULL){
		printf("\nError reservando memoria\n");
		exit(-1);
	}

	return puntero;
}
/**--------------------------------------------------------------------------------------------------------------

	@fn extraeMayores(int ** matriz,int f,int c,int corte,int * e)
	@brief Extrae los elementos mayores del elemento de corte de la matriz y los devuelve en un vector
	@param matriz Puntero a la matriz de donde extraer
	@param f Numero de filas de la matriz
	@param c Numero de columnas de la matriz
	@param corte Elemento de corte a la hora de seleccionar mayores
	@param e Puntero donde almacenar la dimensión del vector resultante
	@pre Matriz debe contener valores
	@return puntero Dirección del vector resultante

	@author Grego Corpas Prieto
	@date 30-03-2015

	Esta función busca los elementos mayores de un número dentro de una matriz y los coloca en un vector dinámico que 
	se devuelve como retorno

--------------------------------------------------------------------------------------------------------------*/

int * extraeMayores(int ** matriz,int f,int c,int corte,int * e){
	int * puntero=NULL;
	int i,j;

	puntero=creaVector(f*c);

	*e=0;
	for(i=0;i<f;i++){
		for(j=0;j<c;j++){
			if(matriz[i][j]>corte){
				puntero[*e]=matriz[i][j];
				*e=(*e)+1;
			}
		}
	}
	puntero=(int *)realloc(puntero,(*e * sizeof(int)));
	
	if(puntero==NULL){
		if(*e!=0){
			printf("\nError reservando memoria\n");
			exit(-1);
		}
	}

	return puntero;
}

/**--------------------------------------------------------------------------------------------------------------

	@fn calculaMaxMin(int ** matriz,int f,int c,int * max,int * min)
	@brief Calcular el mayor y menor elemento de una matriz devolviéndolos por referencia
	@param matriz Puntero a la matriz de donde extraer
	@param f Numero de filas de la matriz
	@param c Numero de columnas de la matriz
	@param max Puntero donde almacenar el elemento de mayor valor
	@param min Puntero donde almacenar el eleemento de menor valor
	@pre La matriz ha de estar rellena
	@return Nada

	@author Grego Corpas Prieto
	@date 30-03-2015

	Esta función busca los valores máximo y mínimo mediante el recorrido iterativo de la matriz, por filas y columnas
	y mediante el uso de punteros devuelve por referencia los valores máximos y mínimos

--------------------------------------------------------------------------------------------------------------*/
void calculaMaxMin(int ** matriz,int f,int c,int * max,int * min){
	int i,j;
	*min=*max=matriz[0][0];

	for(i=0;i<f;i++){
		for(j=0;j<c;j++){
			if(matriz[i][j]>*max){
				*max=matriz[i][j];
			}
			if(matriz[i][j]<*min){
				*min=matriz[i][j];
			}
		}
	}
}


void liberaMatriz(int *** matriz, int f){
	int i;

	for(i=0;i<f;i++){
		free(*((*matriz)+i));
		*(*matriz+i)=NULL;
	}
	free(*matriz);
	*matriz=NULL;
}

void liberaVector(int ** vector){
	free(*vector);
	*vector=NULL;
}
