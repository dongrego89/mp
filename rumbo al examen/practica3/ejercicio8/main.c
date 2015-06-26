#include<stdio.h>

#include "funciones.h"

int main(){

	int opcion,tamano;
	char cadena[MAX_T],nombre[FILENAME_MAX];
	libro informacion, * vector=NULL;
	

	printf("\nIntroduce el nombre del fichero donde trabajaremos: ");
	gets(nombre);

	do{	
		system("clear");

		printf("\nMENU DE FICHEROS DE TEXTO\n\n");
	
		printf("\n\t1.Comprobar existencia");
		printf("\n\t2.Introducir nuevo libro");
		printf("\n\t3.Contar numero de libros en el stock");
		printf("\n\t4.Listar el stock");
		printf("\n\t5.Vender libro buscando por titulo");
		printf("\n\t6.Borrar registros con stock 0");
		printf("\n\t7.Salir\n\n");

		printf("Elige tu opcion: ");
		scanf("%d",&opcion);
		getchar();

		switch(opcion){
			case 1:
				printf("\nIntroduce el titulo de un libro para ser buscado: ");
				fgets(cadena,MAX_T,stdin);

				if(existeLibro(nombre,cadena)==1){
					printf("\nHubo coincidencias en la busqueda");
				}
				else{
					printf("\nLibro no encontrado");
				}
	
			break;
			case 2:
				printf("\nIntroduce el titulo del libro:");
				gets(informacion.titulo);
				printf("\nIntroduce el autor del libro:");
				gets(informacion.autor);
				printf("\nIntroduce el precio:");
				scanf("%f",&(informacion.precio));
				getchar();
				printf("\nIntroduce las unidades en stock:");
				scanf("%d",&(informacion.unidades));
				getchar();

				nuevoLibro(nombre,informacion);
				
				printf("\nLibro añadido al registro");
			
			break;
			case 3:
				printf("\nExisten %d libros registrados en el fichero",cuentaLibros(nombre));
			break;
			case 4:
				tamano=cuentaLibros(nombre);
				vector=reservaMemoria(tamano);
				rellenaVector(nombre,vector,tamano);
				imprimeStock(vector,tamano);
				//guardaBinario(vector,tamano,"binario.bin");
			break;
			case 5:

			break;
			case 6:

			break;
		}
	
		getchar();
	
	}while(opcion!=7);

	system("clear");

	return 0;
}
