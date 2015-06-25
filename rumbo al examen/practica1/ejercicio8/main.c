#include<stdio.h>

#include "funciones.h"

int main(){

	system("clear");

	datos * vector=NULL,mayor,menor;
	int numPersonas,i;

	printf("\nIntroduce el numero de personas a registrar: ");
	scanf("%d",&numPersonas);
	getchar();

	vector=reservaMemoria(numPersonas);
	
	for(i=0;i<numPersonas;i++){
		leePersona(vector+i);
	}
	for(i=0;i<numPersonas;i++){
		escribePersona(vector[i]);
	}
	

	buscaMayorMenor(vector,numPersonas,&mayor,&menor);
	printf("\n\nLos datos de la persona mayor son:");	
	escribePersona(mayor);
	printf("\n\nLos datos de la persona menor son:");	
	escribePersona(menor);

	printf("\nLa edad media de las personas es %.3f años",calculaEdadMedia(vector,numPersonas));

	getchar();
	
	system("clear");

	return 0;
}
