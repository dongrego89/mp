#include<stdio.h>

#include "ej3.h"

int main(){

	system("clear");
	
	char cadena[150],caracter;
	int cantidad;

	printf("\nIntroduce una cadena de texto: ");
	gets(cadena);

	printf("\nIndica el caracter que vamos a buscar en la cadena: ");
	scanf("%c",&caracter);
	
	cantidad=buscaCaracter(caracter,cadena);

	printf("\nExisten %d coincidencias con el caracter %c en la cadena\n\t\"%s\"\n",cantidad,caracter,cadena);
	return 0;
}
