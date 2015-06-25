#include<stdio.h>

#include "funciones.h"

int main(){

	system("clear");

	int numero;

	printf("\nIntroduce un numero: ");
	scanf("%d",&numero);
	getchar();

	printf("\nEl numero %d tiene %d digitos pares\n",numero,cuentaPares(numero));

	getchar();
		
	system("clear");

	return 0;
}
