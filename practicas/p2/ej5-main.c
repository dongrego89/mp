#include<stdio.h>

#include "ej5.h"

int main(){

	system("clear");

	char ** vector, * concatenacion;
	int numero=0;

	vector=leeCadenas(&numero);

	printf("\nHemos leido un total de %d cadenas\n",numero);
	
	if(numero!=0){
		imprimeCadenas(vector,numero,"\nVector Cadenas:\n");
	}
	
	concatenacion=concatena(vector,numero);
	printf("\nLa cadena concatenada final es: \n\t%s\n",concatenacion);
return 0;
}
