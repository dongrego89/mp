#include<stdio.h>
#include<stdlib.h>

#include "ej3.h"

int main(int argc, char ** argv){

	if(argc!=3){
		printf("\nError invocando el programa\n\t%s [CADENA DE TEXTO] [CARACTER] \n",argv[0]);
		exit(-1);	
	}
	
	printf("\nEl caracter %c se encuentra en la cadena '%s' un total de %d veces\n",argv[2][0],argv[1],cuentaCaracter(argv[1],argv[2][0]));
	

	return 0;
}
