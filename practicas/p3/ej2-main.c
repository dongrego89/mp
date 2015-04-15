#include<stdio.h>
#include "ej2.h"

int main(){

	system("clear");

	int numero,digitos;

	printf("\nIntroduce un numero: ");	
	scanf("%d",&numero);	

	digitos=calculaDigitos(numero);

	printf("\nEl numero %d tiene %d digitos pares\n",numero,digitos);
	
	return 0;
}
