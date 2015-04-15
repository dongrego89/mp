#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "ej4.h"

int main(){

	system("clear");
	
	srand(time(NULL));

	int * vector=NULL;
	int elementos;
	
	printf("\nIntroduce el numero de elementos que tendra el vector: ");
	scanf("%d",&elementos);
	
	vector=reservaMemoria(elementos);
	rellenaVector(vector,elementos);
	imprimeVector(vector,elementos,"\n Vector: ");

	return 0;
}
