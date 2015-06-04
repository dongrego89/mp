#include<stdio.h>
#include<stdlib.h>

#include "funciones.h"

int main(int argc, char ** argv){

	system("clear");

	nodo * lista=NULL, * mayores=NULL, * menores=NULL;
	float precio;

	if(argc!=4){
		printf("\nError invocando al programa:\n\t%s [ORIGINAL] [MAYORES] [MENORES]\n",argv[0]);
		exit(-1);
	}

	if(compruebaFichero(argv[1])!=0){
		printf("\nEl archivo ORIGINAL no existe. Abortando ejecución...\n");
		exit(-1);
	}

	cargaFicheroEnLista(argv[1],&lista);

	printf("\nListado de libros:");	
	imprimeLista(lista);

	printf("\nIndica por que precio de corte separaremos los libros: ");
	scanf("%f",&precio);

	separaPorPrecio(lista,&mayores,&menores,precio);

	printf("\n[+]Listado de libros mayores de %3.3f:",precio);	
	imprimeLista(mayores);

	printf("\n[-]Listado de libros menores de %3.3f:",precio);	
	imprimeLista(menores);

	cargaListaEnFichero(argv[2],mayores);
	cargaListaEnFichero(argv[3],menores);

	
	
	return 0;
}
