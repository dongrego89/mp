#include<stdio.h>

#include "pilas.h"


int buscaContenedor(struct nodo ** cima, int elemento){
	struct nodo * cima_aux;
	int encontrado=0;
	
	while((pilaVacia(*cima)==0) && (encontrado==0)){
		if((*cima)->numero==elemento){
			encontrado=1;	
		}
		//printf("\n[-]Desapilando de cima principal el elemento con valor %d",(*cima)->numero);
		push(&cima_aux,pop(cima));
	}
	//Devolver los elementos sacados de la pila
	while(pilaVacia(cima_aux)!=1){
		//printf("\n[-]Reapilando el elemento con valor %d",cima_aux->numero);
		push(cima,pop(&cima_aux));
	}
	
	return encontrado;
}
