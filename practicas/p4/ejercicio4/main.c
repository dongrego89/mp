#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "funciones.h"

int main(){
	
	system("clear");
	srand(time(NULL));

	char opcion;
	void * vector=NULL;
	int elementos;

	printf("\nTipos de dato para el vector:");
	printf("\n\t[i] Entero");
	printf("\n\t[l] Entero largo");
	printf("\n\t[f] Decimal");
	printf("\n\t[d] Doble decimal");
	printf("\nTu opcion: ");
	
	do{

		scanf("%c",&opcion);
		getchar();

	}while(opcion!='i' && opcion !='l' && opcion!='f' && opcion!='d');

	printf("\nIntroduce el numero de elementos que tendrá el vector: ");
	scanf("%d",&elementos);

	vector=reservaMemoria(elementos,opcion);
	rellenaVectorAleatorio(vector,elementos,opcion);
	imprimeVector(vector,elementos,opcion,"\nImpresion de vector:\n");

	return 0;
}
