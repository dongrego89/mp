#include<stdio.h>
#include<string.h>

#include "ej9.h"

int main(){

	system("clear");

	char cadena[50],prefijo[25];

	printf("Introduce una cadena: ");
	fgets(cadena,50,stdin);

	printf("Introduce el prefijo a buscar: ");
	fgets(prefijo,25,stdin);

	corrige(cadena);
	corrige(prefijo);

	if(esPrefijo(cadena,prefijo)){
		printf("\n%s es prefijo de %s\n",prefijo,cadena);
	}
	else{
		printf("\n%s no es prefijo de %s\n",prefijo,cadena);
	}

	return 0;
}
