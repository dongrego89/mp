#include<stdio.h>

#include "funciones.h"

int main(){

	system("clear");

	char cadena[MAX_CHAR],nuevo,viejo;


	printf("\nIntroduce la cadena: ");
	gets(cadena);
	printf("\nIntroduce el caracter a sustituir y el nuevo: ");
	scanf("%c %c",&viejo,&nuevo);
	getchar();

	printf("\nCadena antes de reemplazar: \n\t '%s'",cadena);

	replace(cadena,nuevo,viejo);

	printf("\nCadena despues de reemplazar: \n\t '%s'",cadena);

	getchar();
	
	system("clear");

	return 0;
}
