#include<string.h>

#include "funciones.h"

void replace (char *s, char nuevo, char viejo){
	
	char * posicion;

	while((posicion=strchr(s,viejo))!=NULL){
		*posicion=nuevo;
	}

}
