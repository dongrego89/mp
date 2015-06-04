#include<stdio.h>
#include<stdlib.h>

#include "funciones.h"

int main(int argc, char ** argv){
	
	system("clear");

	if(argc!=5){
		printf("\nError en la invocación del programa:\n\t%s [FUENTE] [NIÑOS] [NIÑAS] [MEZCLA]\n",argv[0]);
		exit(-1);		
	}

	if(compruebaFichero(argv[1])!=0){
		printf("\nNo existe el fichero fuente. Abortando ejecución...");
		exit(-1);
	}

	actualizaEdad(argv[1]);
	distribuyePorSexo(argv[1],argv[2],argv[3]);
	mezclaAlumnos(argv[4],argv[2],argv[3]);
	
	return 0;
}
