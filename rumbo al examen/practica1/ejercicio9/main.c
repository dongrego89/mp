#include<stdio.h>

#include "funciones.h"

int main(){

	system("clear");

	char cadena[MAX_CHAR], prefijo[MAX_CHAR];

	printf("\nIntroduce la cadena: ");
	gets(cadena);
	printf("\nIntroduce el prefijo: ");
	gets(prefijo);
	
	if(es_prefijo(cadena,prefijo)==1){
		printf("\n %s es prefijo de %s\n",prefijo,cadena);
	}
	else{
		printf("\n %s NO es prefijo de %s\n",prefijo,cadena);
	}
	

	getchar();
	
	system("clear");

	return 0;
}
