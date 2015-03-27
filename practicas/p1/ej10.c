#include<string.h>
#include "ej10.h"

void replace(char * s, char nuevo, char viejo){
	char * caracter,* direccion=s;

	while((caracter=strchr(direccion,viejo))!=NULL){
		*caracter=nuevo;
		direccion=caracter;	
	}
}
