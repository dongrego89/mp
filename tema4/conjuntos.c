#include<stdio.h>
#include<stdlib.h>

#include "conjuntos.h"

elemento * reservaMemoria(){
	elemento * puntero=NULL;
	
	puntero=(elemento *)malloc(sizeof(elemento));
	if(!puntero){
		printf("\nError reservando memoria\n");
		exit(-1);
	}
	return puntero;
}

int introduceElemento(elemento ** cabeza, int valor){

	elemento * nuevo=NULL, * auxiliar=NULL;

	//if(perteneceConjunto(*cabeza,valor)==0){//Si no se encontró 	//
		
		nuevo=reservaMemoria();//Reservamos memoria e inicializamos valores
		nuevo->siguiente=NULL;
		nuevo->valor=valor;

		if(estaVacio(*cabeza)==1){//Será el primer elemento a introducir en la lista si no hay mas elementos en el conjunto
			*cabeza=nuevo;
		}
		else{//Se insertará a continuación del siguiente elemento
			auxiliar=*cabeza;
			while(auxiliar->siguiente!=NULL){
				auxiliar=auxiliar->siguiente;
			}
			auxiliar->siguiente=nuevo;
		}
	return 1;//Se introdujo este elemento
	//}//
	//return 0;//No se introdujo este elemento debido a duplicidad//
}

int perteneceConjunto(elemento * cabeza,int valor){
	
	elemento * auxiliar=NULL;
	
	if(estaVacio(cabeza)==1){//La lista está vacía, por tanto, no pertecene al conjunto
		return 0;
	}
	else{
		auxiliar=cabeza;
		while(auxiliar!=NULL){//Recorremos iterativamente la lista
			if(auxiliar->valor==valor){
				return 1; //Si encontramos el valor, devolvemos 1
			}
			auxiliar=auxiliar->siguiente;
		}
	}
	return 0;//Si no se encontró el valor, no está en el conjunto
}

int estaVacio(elemento * cabeza){	
	
	if(cabeza==NULL){
		return 1;
	}
	return 0;
}

/* Función de impresión sin recursividad
void imprimeConjunto(elemento * cabeza, char * mensaje){
	
	elemento * auxiliar=NULL;

	printf("%s",mensaje);

	if(estaVacio(cabeza)==1){
		printf("\nNo existen elementos en el conjunto");
	}
	else{
		auxiliar=cabeza;
		while(auxiliar!=NULL){
			printf("\nValor: %d",auxiliar->valor);
			auxiliar=auxiliar->siguiente;
		}
	}
	printf("\n");
}
*/

void imprimeConjunto(elemento * cabeza, char * mensaje){

	if(cabeza==NULL){
		printf("%s",mensaje);
	}
	else{
		imprimeConjunto(cabeza->siguiente,mensaje);
		printf("\tElemento: %d\n",cabeza->valor);
	}
}

int cuentaElementos(elemento * cabeza){
	
	elemento * auxiliar=NULL;
	int cuenta=0;
	
	if(estaVacio(cabeza)==1){
		return cuenta;
	}
	else{
		auxiliar=cabeza;
		while(auxiliar!=NULL){
			cuenta+=1;
			auxiliar=auxiliar->siguiente;
		}
	}
	return cuenta;
}

elemento * uneConjuntos(elemento * conjuntoA, elemento * conjuntoB){

	elemento * auxiliar=NULL, * retorno=NULL;

	if((estaVacio(conjuntoA)==1) && (estaVacio(conjuntoB)==1)){//Si estan vacios ambos conjuntos se devolverá NULL
		return NULL;
	}

	if((estaVacio(conjuntoA)==1) && (estaVacio(conjuntoB)==0)){//Si esta vacio solo el conjunto A, la unión será conjunto B
		return conjuntoB;
	}
	
	if((estaVacio(conjuntoB)==1) && (estaVacio(conjuntoA)==0)){//Si esta vacio solo el conjunto B, la unión será conjunto A
		return conjuntoA;
	}

	//Si llegamos a esta parte es porque ninguno de los dos está vacío, por tanto rellenaremos con un conjunto y añadiremos los que no existan aún del otro

	auxiliar=conjuntoA;

	while(auxiliar!=NULL){// Hasta que lleguemos al último nodo del conjunto A

		introduceElemento(&retorno,auxiliar->valor);
		
		auxiliar=auxiliar->siguiente;
	}
	
	auxiliar=conjuntoB;

	while(auxiliar!=NULL){// Hasta que lleguemos al último nodo del conjunto B
		if(perteneceConjunto(retorno,auxiliar->valor)==0){ // Si no existe el elemento de conjunto B en conjunto A (retorno)
			introduceElemento(&retorno,auxiliar->valor); // Lo añadimos	
		}
		auxiliar=auxiliar->siguiente;
	}

	return retorno;
}


elemento * intersectaConjuntos(elemento * conjuntoA, elemento * conjuntoB){

	elemento * auxiliar=NULL, * retorno=NULL;

	if((estaVacio(conjuntoA)==1) || (estaVacio(conjuntoB)==1)){//Si uno de los dos conjuntos está vacío no existirá intersección
		return NULL;
	}

	auxiliar=conjuntoA;

	while(auxiliar!=NULL){
		if(perteneceConjunto(conjuntoB,auxiliar->valor)){//Si el elemento de A se encuentra también en B
			introduceElemento(&retorno,auxiliar->valor);
		}
		auxiliar=auxiliar->siguiente;
	}

	return retorno;
}
