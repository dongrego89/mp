#include<stdio.h>
#include<stdlib.h>

#include "funciones.h"

int main(){

	system("clear");

	int columnas,filas,borrar, ** matriz=NULL;

	printf("\nIntroduce el Nº de filas de la matriz: ");
	scanf("%d",&filas);
	getchar();

	printf("\nIntroduce el Nº de columnas de la matriz: ");
	scanf("%d",&columnas);
	getchar();

	matriz=reservarMemoria(filas,columnas);

	rellenaMatriz(matriz,filas,columnas);

	imprimeMatriz(matriz,filas,columnas);

	printf("\nIntroduce el numero de fila [0-%d] a borrar: ",filas-1);
	scanf("%d",&borrar);
	getchar();

	matriz=eliminarFila(matriz,filas,columnas,borrar);

	filas-=1;
	
	imprimeMatriz(matriz,filas,columnas);

	liberarMemoria(&matriz,filas);

	if(matriz==NULL){
		printf("\nMemoria liberada con exito...\n");
	}
	else{
		printf("\nError liberando memoria...\n");
		exit(-1);
	}

	getchar();

	system("clear");

	return 0;
}
