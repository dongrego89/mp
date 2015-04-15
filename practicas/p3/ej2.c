#include<stdio.h>

#include "ej2.h"

int calculaDigitos(int numero){
	
	int resultado=0;

	if(numero<=0){
		resultado=0;
	}
	else{

		if(numero%2==0){
			resultado=1;
		}

		resultado+=calculaDigitos(numero/10);

	}

	return resultado;

}
