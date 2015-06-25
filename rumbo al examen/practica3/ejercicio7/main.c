#include<stdio.h>

#include "funciones.h"

int main(){

	system("clear");

	char nombre[FILENAME_MAX];

	printf("\nIntroduce el nombre del fichero a modificar: ");	
	gets(nombre);

	trim(nombre);

	getchar();

	system("clear");

	return 0;
}
