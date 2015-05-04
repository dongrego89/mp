#include<stdio.h>
#include "ej2.h"


int calculaPares(int numero){
	int pares=0;

	if(numero>10){ // Si no es la ultima iteración
		if( ((numero%10) % 2 == 0) && ((numero%10) != 0) ){ // Si el resto de numero entre 10 es par y no cero, el digito menos significativo es par 
			pares=1;
		}	
		return pares+calculaPares(numero/10);
	}
	else{
		if((numero % 2 == 0) && (numero != 0)){ // Estamos en el último dígito, comprobamos si es par y si es no es cero
			pares=1;
			printf("[%d]",numero);
		}
		return pares;
	}

}
