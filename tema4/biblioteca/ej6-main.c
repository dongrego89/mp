#include<stdio.h>

#include "pilas.h"

int main(){
	
	struct nodo * lista;
	int i, elementos, valor, busqueda;

	printf("\nIntroduce el numero de elementos que quieres apilar: ");
	scanf("%d",&elementos);
	
	for(i=0;i!=elementos;i++){
		printf("[+]Introduce el elemento %d: ",i+1);
		scanf("%d",&valor);
		push(&lista,valor);
	}

	printf("\nIntroduce el elemento a buscar en la pila: ");
	scanf("%d",&busqueda);

	if(buscaContenedor(&lista,busqueda)!=0){
		printf("\nElemento encontrado");
	}	
	else{
		printf("\nElemento no encontrado");
	}

	if(buscaContenedor(&lista,busqueda)!=0){
		printf("\nElemento encontrado");
	}	
	else{
		printf("\nElemento no encontrado");

	return 0;
}
