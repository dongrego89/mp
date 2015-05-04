#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "ej8.h"

int main(){

	int opcion, elementos;
	char titulo[MAX_CHAR];
	registro auxiliar, * vector=NULL;
	

	do{
		printf("GESTION DE LIBRERIA | BBDD '%s'\n",BBDD);
		printf("******************************************************************\n\n");
		printf("1 · Comprobar existencia de un libro\n");
		printf("2 · Introducir un libro en el stock\n");
		printf("3 · Contar los libros existentes en el stock\n");
		printf("4 · Listar los libros existentes en el stock\n");
		printf("5 · Vender un libro\n");
		printf("6 · Borrar del stock los registros sin libros\n\n");
		printf("0 · Salir\n\n");
		printf("******************************************************************\n\n");

		printf("Su opcion: ");
		scanf("%d",&opcion);
		getchar();
		
		switch(opcion){
			case 1:
				printf("\nIntroduce el titulo del libro a buscar: ");
				gets(titulo);

				if((compruebaLibro(titulo))==1){			
					printf("\nEl libro '%s' se encuentra en el stock",titulo);
				}
				else{
					printf("\El libro '%s' no se encuentra en el stock",titulo);
				}
			break;

			case 2:
				printf("\nIntroduce el titulo del nuevo libro: ");
				gets(auxiliar.titulo);
			
				printf("\nIntroduce el nombre del autor del nuevo libro: ");
				gets(auxiliar.autor);
	
				printf("\nIntroduce el precio del nuevo libro: ");
				scanf("%f",&auxiliar.precio);
				getchar();

				printf("\nIntroduce las unidades de stock del nuevo libro: ");
				scanf("%d",&auxiliar.unidades);
				getchar();
	
				introduceLibro(auxiliar);
		
				printf("\nLibro añadido al registro");
			break;

			case 3:
				printf("\nExisten un total de %d libros registrados en el stock",cuentaLibros());
			break;

			case 4:
				printf("\nListado de libros registrados en el stock:\n");

				elementos=cuentaLibros();		
				
				vector=reservaMemoria(elementos);
				vuelcaFichero(vector);
				listaLibros(vector,elementos);

				free(vector);
				vector=NULL;
				
			break;

			case 5:
				printf("\nIntroduce el titulo del libro que quieres vender: ");
				gets(titulo);

				switch(vendeLibro(titulo)){
					case 0:
						printf("\nNo se encontró el libro.");
					break;
					case 1:
						printf("\nLibro vendido. Stock modificado");
					break;
					case 2:
						printf("\nNo se pudo vender porque no hay existencias.");
					break;						
				}
			break;

			case 6:
				printf("\nEliminando registros del stock con 0 unidades disponibles");
				borraCero();
			break;

			case 0:
				// Salir
			break;

			default:
				printf("\nIntroduce un valor valido [0-6]");
			break;
		}
		
		getchar(); // Pausa		

	}while(opcion!=0);

	return 0;
}
 
