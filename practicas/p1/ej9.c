#include<string.h>

#include "ej9.h"


int esPrefijo(char * cadena, char * prefijo){

	if(strstr(cadena,prefijo)==cadena){
		return 1;	
	}
	else{
		return 0;	
	}

}
void corrige(char * s){
	s[strlen(s)-1]='\0';
}
