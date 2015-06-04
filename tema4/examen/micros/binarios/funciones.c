#include<stdio.h>
#include<stdlib.h>

#include "funciones.h"

int compruebaFichero(char * nombre){
	FILE * fichero=NULL;
	
	fichero=fopen(nombre,"r");

	if(!fichero){
		return -1;
	}
	else{
		fclose(fichero);
		return 0;
	}
}

nodo * reservaMemoria(){
	
	nodo * puntero=NULL;

	puntero=(nodo *)malloc(sizeof(nodo));
	if(!puntero){
		printf("\nError reservando memoria\n");
		exit(-1);
	}
	return puntero;
}

void nuevoNodo(nodo ** cabeza, libro elemento){
	
	nodo * nuevo=NULL, * aux=NULL;

	nuevo=reservaMemoria();
	
	nuevo->siguiente=NULL;
	nuevo->contenido=elemento;

	if(*cabeza==NULL){//Si la cabeza no apunta a ningun lado
		*cabeza=nuevo;//Nuevo será el primer elemento
	}
	else{//Si no es el primer elemento en la lista, entonces...
		aux=*cabeza;
		while(aux->siguiente!=NULL){//Mientras no lleguemos al ultimo elemento
			aux=aux->siguiente;
		}
		aux->siguiente=nuevo;//El siguiente elemento será el elemento nuevo
	}

}

void cargaFicheroEnLista(char * nombre, nodo ** cabeza){
	
	FILE * fichero=NULL;
	libro auxiliar;

	fichero=fopen(nombre,"r");

	if(!fichero){
		printf("\nError abriendo fichero\n");
		exit(-1);
	}
	
	while(fread(&auxiliar,sizeof(libro),1,fichero)){
		nuevoNodo(cabeza,auxiliar);
	}

	fclose(fichero);
}

void imprimeLista(nodo * cabeza){

	if(cabeza!=NULL){
		printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
		printf("\n* Titulo: %s",cabeza->contenido.titulo);
		printf("* Autor: %s",cabeza->contenido.autor);
		printf("* Precio: %2.3f",cabeza->contenido.precio);
		printf("\n* Unidades: %d",cabeza->contenido.unidades);
		imprimeLista(cabeza->siguiente);
	}
	else{
		printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	}

}

void separaPorPrecio(nodo * cabeza,nodo ** mayores, nodo ** menores,float precio){

	libro auxiliar;

	if(cabeza!=NULL){//Si no estamos en el ultimo elemento aun
		auxiliar=cabeza->contenido;

		if(auxiliar.precio>=precio){
			nuevoNodo(mayores,auxiliar);//Añadir nuevo nodo a mayores
		}
		else{
			nuevoNodo(menores,auxiliar);//Añadir nuevo nodo a menores
		}
		separaPorPrecio(cabeza->siguiente,mayores,menores,precio);
	}
}

void cargaListaEnFichero(char * nombre, nodo * cabeza){
	
	FILE * fichero=NULL;

	if(cabeza!=NULL){

		fichero=fopen(nombre,"a");

		if(!fichero){
			printf("\nError abriendo fichero\n");
			exit(-1);
		}

		fwrite(&(cabeza->contenido),sizeof(libro),1,fichero);

		fclose(fichero);

		cargaListaEnFichero(nombre,cabeza->siguiente);
	}
}
