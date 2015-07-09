#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "funciones.h"

int loginUsuario(){
	
	char clave[MAX_CHAR];	

	printf("\nIntroduce la clave: ");
	scanf("%s",clave);
	getchar();
	
	return strcmp(CLAVE,clave);
	
}

int menu(){

	int opcion;

	system("clear");

	printf("\nMENU DEL GESTOR DE PUNTOS\n\n");
	printf("\n\t1. Ingresar puntos");
	printf("\n\t2. Retirar puntos");
	printf("\n\t3. Salir");

	printf("\n\tIntroduce tu opcion: ");
	scanf("%d",&opcion);
	getchar();

	return opcion;

}

int sumaPuntos(char * codigo,int puntos){

	char nombreFich[FILENAME_MAX], nomCliente[MAX_CHAR];
	int puntosFich;

	FILE * fichero=NULL;

	strcpy(nombreFich,codigo);
	strcat(nombreFich,".txt");

	fichero=fopen(nombreFich,"r");
		
	if(!fichero){
		return -1;
	}
	
	fscanf(fichero,"%d\n",&puntosFich);
	fgets(nomCliente,MAX_CHAR,fichero);

	fclose(fichero);

	//Ya tenemos los datos, ahora los modificamos y guardamos de nuevo
	
	fichero=fopen(nombreFich,"w");
		
	if(!fichero){
		return -1;
	}
	fprintf(fichero,"%d\n",puntosFich+puntos);
	fputs(nomCliente,fichero);

	fclose(fichero);

	return 1;
}
