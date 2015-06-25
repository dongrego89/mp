#include<stdio.h>
#include<stdlib.h>

#include "funciones.h"
#include "funciones2.h"

int main(){

	system("clear");

	int ** matrizA=NULL, ** matrizB=NULL, ** matrizC=NULL;
	int ca,cb,fa,fb;

	printf("\nIntroduce las dimensiones filas x columnas de la matriz A: ");
	scanf("%d %d",&fa,&ca);
	getchar();

	printf("\nIntroduce las dimensiones filas x columnas de la matriz B: ");
	scanf("%d %d",&fb,&cb);	
	getchar();

	matrizA=reservarMemoria(fa,ca);
	matrizB=reservarMemoria(fb,cb);
		
	rellenaMatriz(matrizA,fa,ca);
	rellenaMatriz(matrizB,fb,cb);

	printf("\nImprimimos matriz A y matriz B:");

	imprimeMatriz(matrizA,fa,ca);
	imprimeMatriz(matrizB,fb,cb);
	

	if(ca!=fb){
		printf("\nNo se puede multiplicar matriz A x matriz B porque las dimensiones son incompatibles \n");
	}
	else{
		matrizC=reservarMemoria(fa,cb);
		multiplicacion(matrizA,matrizB,matrizC,fa,ca,cb);
		imprimeMatriz(matrizC,fa,cb);	
		liberarMemoria(&matrizC,fa);
	}

		liberarMemoria(&matrizA,fa);
		liberarMemoria(&matrizB,fb);

	if(matrizA==NULL && matrizB==NULL && matrizC==NULL){
		printf("\nMemoria liberada correctamente\n");
	}
	else{
		printf("\nError liberando memoria...\n");
		exit(-1);
	}

	getchar();

	system("clear");

	return 0;
}
