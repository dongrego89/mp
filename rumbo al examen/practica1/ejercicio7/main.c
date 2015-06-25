#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "funciones.h"

int main(){

	system("clear");

	srand(time(NULL));	
	
	float examen[MAX_VECTOR],mediaA,mediaB,minA,minB,maxA,maxB;

	rellenaVector(examen,MAX_VECTOR);
	
	imprimeVector(examen,MAX_VECTOR);


	calculaEstadisticas(examen,MAX_VECTOR,&mediaA, &mediaB, &minA, &minB, &maxA, &maxB);

	printf("\n\tExamen A:\n\t\tNota Maxima: %.2f\n\t\tNota Minima: %.2f\n\t\tNota Media: %.2f",maxA,minA,mediaA);
	printf("\n\tExamen B:\n\t\tNota Maxima: %.2f\n\t\tNota Minima: %.2f\n\t\tNota Media: %.2f",maxB,minB,mediaB);

	getchar();

	system("clear");	

	return 0;
}
