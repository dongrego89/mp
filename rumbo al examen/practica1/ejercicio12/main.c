#include<stdio.h>

#include "funciones.h"

int main(){

	system("clear");

	int * matriz,filas, columnas;	

	printf("\nIntroduce el numero de filas que tendra la matriz: ");
	scanf("%d",&filas);
	getchar();

	printf("\nIntroduce el numero de columnas que tendra la matriz: ");
	scanf("%d",&columnas);
	getchar();

	matriz=reservaMemoria(filas*columnas);

	leeMatriz(matriz,filas,columnas);
	escribeMatriz(matriz,filas,columnas);

	liberaMemoria(&matriz);

	if(matriz==NULL){
		printf("\nMemoria liberada...");
	}
	else{
		printf("\nError liberando memoria...");
		return(-1);
	}

	getchar();

	system("clear");

	return 0;
}
