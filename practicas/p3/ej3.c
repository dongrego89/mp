#include<stdio.h>

#include "ej3.h"


int cuentaCaracter(char * cadena, char caracter){

	int cuenta=0;

	if(cadena[0]!='\0'){
		if(cadena[0]==caracter){
			cuenta=1;
		}
		return cuenta + cuentaCaracter(cadena+1,caracter);
	}
	else{
		return cuenta;
	}
}
