#include<stdio.h>
#include<string.h>

int esPrefijo(char * cadena, char * prefijo);

int main(){

	char cadena[30], subCadena[15];
	system("clear");

	printf("Introduce una cadena de texto: ");
	scanf("%s",cadena);
	printf("Introduce la subcadena a buscar: ");
	scanf("%s",subCadena);

	if(esPrefijo(cadena,subCadena)==1){
		printf("\n\tCoincidencia encontrada, la subcadena %s es prefijo de la cadena %s\n",subCadena,cadena);
	}
	else{
		printf("\n\tUna mala tarde la tiene cualquiera\n");
	}

return 0;
}

int esPrefijo(char * cadena, char * prefijo){

	int acierto=0;
	
	if((strstr(cadena,prefijo) == cadena)){//Si se encuentra la subcadena en cadena, y además la coincidencia comienza en la posición 0 del array
		acierto=1;
	}	
	
	return acierto;
}
