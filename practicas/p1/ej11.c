#include<stdio.h>
#include "ej11.h"

int menu(){
	int opcion;
	system("clear");
	printf("Menu:\n");
	printf("--------------------------\n");
	printf("\t1. Lectura\n");
	printf("\t2. Escritura\n");
	printf("\t3. Media Aritmetica\n");
	printf("\t4. Salir\n");
	printf("--------------------------\n");
	printf("Opcion: ");
	scanf("%d",&opcion);
return opcion;
}



void lectura(double * valores){
	int i;
	for(i=0;i<N;i++){
		printf("\tValores[%d]: ",i);
		scanf("%lf",&valores[i]);
	}
}

void escritura(double * valores){
	int i;
	for(i=0;i<N;i++){
		printf("\tValores[%d]: %.2lf\n",i,valores[i]);
	}
}

double mediaAritmetica(double * valores){
	int i;
	double sumatorio=0;

	for(i=0;i<N;i++){
		sumatorio+=valores[i];
	}
	return sumatorio/N;
}


