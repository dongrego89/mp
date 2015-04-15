#include<stdio.h>

#include "ej3.h"

int buscaCaracter(char caracter,char * cadena){

	int resultado=0;		

	printf("Se busca %c en %s\n", caracter, cadena);	

	if(*cadena=='\0'){
		resultado = 0;
	}
	else{//Si no es el caso base
		if(*cadena==caracter){
			resultado=1;
		}	
		resultado+=buscaCaracter(caracter,cadena+1);
	}

	return resultado;
}
