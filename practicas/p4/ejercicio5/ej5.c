#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "ej5.h"

monomio * reservaMemoria(){
	monomio * puntero=NULL;

	puntero=(monomio *)malloc(sizeof(monomio));

	if(!puntero){
		printf("\nError reservando memoria\n");
		exit(-1);
	}
	
	return puntero;
}

void pushFront(monomio ** cabeza, int c, int e){

	monomio * nuevo=NULL, * auxiliar=NULL;
	
	nuevo=reservaMemoria();

	nuevo->siguiente=NULL;
	nuevo->exponente=e;
	nuevo->coeficiente=c;

	if(*cabeza==NULL){//Si no existía ningún elemento antes del nuevo
		*cabeza=nuevo;
	}
	else{
		auxiliar=*cabeza;//Almacenamos temporalmente cabeza
		nuevo->siguiente=auxiliar;//Nuevo apunta como siguiente al que fue la cabeza 
		*cabeza=nuevo;//La cabeza es ahora el nuevo elemento
	}
}

void muestraPolinomio(monomio * polinomio){

	monomio * aux=polinomio->siguiente;
	
	
		
	if(polinomio->siguiente!=NULL){
		muestraPolinomio(aux);
	}
	
	printf(" %dx^%d ",polinomio->coeficiente,polinomio->exponente);

}

float evaluaPolinomio(monomio * polinomio,float x){
	float resTotal=0;
	float resMonomio=0;
	monomio * auxiliar;
		
	auxiliar=polinomio;
	while(auxiliar!=NULL){
		resMonomio=auxiliar->coeficiente * pow(x,auxiliar->exponente);
		resTotal+=resMonomio;
		auxiliar=auxiliar->siguiente;
	}

	return resTotal;
}


