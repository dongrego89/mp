#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "funciones.h"

int main(){

	system("clear");

	srand(time(NULL));//Semilla generadora de aleatorios

	int elementos, * vector=NULL;
	
	printf("\nIntroduce el numero de elementos que tendrá el vector: ");
	scanf("%d",&elementos);	
	getchar();

	vector=reservaMemoria(elementos);

	rellenaVector(vector,elementos);

	imprimeVector(vector,elementos);

	extraeImpares(&vector,&elementos);

	imprimeVector(vector,elementos);

	liberaMemoria(&vector);

	if(vector==NULL){
		printf("\nMemoria Liberada correctamente...\n");
	}
	else{
		printf("\nError liberando memoria...\n");
		exit(-1);
	}

	getchar();

	system("clear");

	return 0;
}
