#include<stdio.h>
#include<stdlib.h>

#include "funciones.h"

int main(){

	system("clear");

	ficha * vector=NULL;
	int jugadores;
	char caracter;	
	
	printf("\nIntroduce el numero de elementos a registrar: ");
	scanf("%d",&jugadores);
	getchar();

	vector=reservaMemoria(jugadores);

	rellenaVector(vector,jugadores);

	imprimeVector(vector,jugadores);
	
	printf("\nIntroduce el caracter por el que borraremos a los elementos del vector: ");
	scanf("%c",&caracter);
	getchar();

	borraPorCaracter(&vector,&jugadores,caracter);
	
	imprimeVector(vector,jugadores);
	
	liberaMemoria(&vector);

	if(vector==NULL){
		printf("\nMemoria liberada con exito\n");
	}
	else{
		printf("\nError liberando memoria\n");
		exit(-1);
	}

	getchar();

	system("clear");

	return 0;
}
