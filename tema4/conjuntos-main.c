#include<stdio.h>

#include "conjuntos.h"

int main(){
	
	system("clear");

	int elementos,i,valor;
	elemento * conjuntoA=NULL, * conjuntoB=NULL, * conjuntoC=NULL,* conjuntoD=NULL;

	printf("\nIntroduce el numero de elementos a insertar en [Conjunto A]: ");
	scanf("%d",&elementos);
	
	for(i=0;i<elementos;i++){
		do{
			printf("\t[+]Elemento [%2d] de [Conjunto A]: ",i+1);	
			scanf("%d",&valor);
			if(perteneceConjunto(conjuntoA,valor)==1){
				printf("\n\tElemento repetido, prueba con otro valor\n");	
			}
		}while(perteneceConjunto(conjuntoA,valor)==1);//Si este elemento ya existe, lo volveremos a pedir

		introduceElemento(&conjuntoA,valor);
	}

	printf("\nIntroduce el numero de elementos a insertar en [Conjunto B]: ");
	scanf("%d",&elementos);
	
	for(i=0;i<elementos;i++){
		do{
			printf("\t[+]Elemento [%2d] de [Conjunto B]: ",i+1);	
			scanf("%d",&valor);
			if(perteneceConjunto(conjuntoB,valor)==1){
				printf("\n\tElemento repetido, prueba con otro valor\n");	
			}
		}while(perteneceConjunto(conjuntoB,valor)==1);//Si este elemento ya existe, lo volveremos a pedir

		introduceElemento(&conjuntoB,valor);
	}

	imprimeConjunto(conjuntoA,"\n[Conjunto A]:\n");
	imprimeConjunto(conjuntoB,"\n[Conjunto B]:\n");

	conjuntoC=uneConjuntos(conjuntoA,conjuntoB);
	
	imprimeConjunto(conjuntoC,"\n[Conjunto C][A union B]:\n");

	conjuntoD=intersectaConjuntos(conjuntoA,conjuntoB);
	
	imprimeConjunto(conjuntoD,"\n[Conjunto D][A interseccion B]:\n");

	return 0;
}


