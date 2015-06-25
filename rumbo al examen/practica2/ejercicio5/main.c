#include<stdio.h>
#include<stdlib.h>

#include "funciones.h"

int main(){

	system("clear");

	char ** vectorFrases=NULL, * frase=NULL;
	int numero;
	
	vectorFrases=leeFrases(160,'$',&numero);

	imprimeFrases(vectorFrases,numero);

	frase=concatenaFrases(vectorFrases,numero);

	printf("\nLa frase final es:\n\t'%s'\n",frase);

	liberaMemoria(&vectorFrases,numero);	
	
	if(vectorFrases==NULL){
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
