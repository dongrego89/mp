#include<string.h>

#include "funciones.h"

int es_prefijo(char * cadena, char * prefijo){

	if(strstr(cadena,prefijo)==cadena){//Cuando lo encuentre debe ser igual a la direccion del primer elemento de cadena
		return 1;
	}
	return 0;
}
