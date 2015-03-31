#include<stdio.h>

#include "ejercicio3.h"

int main(){

	system("clear");

	struct estudiante * vector=NULL;
	int numero;
	float longitud;		
	
	printf("\n¿Cuantos estudiantes vamos a registrar?: ");
	scanf("%d",&numero);

	vector=reservaMemoria(numero);
	rellenaVector(vector,numero);
	imprimeVector(vector,numero);
	
	longitud=calculaMediaNombre(vector,numero);

	printf("\nLa longitud media de los nombres de estudiante es %.2f\n",longitud);
	
	liberaMemoria(&vector);

	if(vector==NULL){
		printf("\nMemoria liberada con exito !!\n");
	}	
	else{
		printf("\nError liberando memoria\n");
		exit(-1);
	}
	return 0;
}
