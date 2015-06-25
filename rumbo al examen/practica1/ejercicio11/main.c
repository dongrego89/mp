#include<stdio.h>

#include "funciones.h"

int main(){

	system("clear");

	double valores[N];
	int elementos;

	leeValores(valores,&elementos);
	escribeValores(valores,elementos);
	
	printf("\nEl valor medio del vector valores es %lf \n",mediaValores(valores,elementos));

	getchar();

	system("clear");

	return 0;
}
